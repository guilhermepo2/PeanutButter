#include "pbpch.h"
#include "Application.h"
#include "PeanutButter/Log.h"
#include "PeanutButter/Utils/AssetManager.h"
#include "PeanutBUtter/Entity/Component/Sprite.h"
#include "PeanutButter/Math/Math.h"
#include "PeanutButter/Window.h"
#include "PeanutButter/Input/Input.h"

const unsigned int FPS = 60;
const unsigned int FRAME_TARGET_TIME = 1000 / FPS;

namespace PeanutButter {

	EntityManager* Application::s_EManager = new EntityManager();
	bool Application::s_bSDL2Initialized = false;
	SDL_Renderer* Application::s_Renderer = nullptr;
	Window* Application::s_Window = nullptr;
	AssetManager* Application::s_AssetManager = new AssetManager(s_EManager);
	SDL_Rect Application::s_Camera = { 0, 0, 640, 360};
	ParticleSystem Application::s_ParticleSystem;

	Application::Application() : m_TicksLastFrame(0.0f) {
		Initialize();
	}

	void Application::Initialize() {
		if (!s_bSDL2Initialized) {
			int Sucess = SDL_Init(SDL_INIT_EVERYTHING);
			PB_CORE_ASSERT(Success, "Could not initialize SDL2");
			PB_CORE_INFO("Initialized SDL2!");
			s_bSDL2Initialized = true;
		}

		int TTFSuccess = TTF_Init();
		PB_CORE_ASSERT(!TTFSuccess, "Could Not Initialize TTF!");

		// /////////////////////////////////////////////////////////////////////////////////
		// Loading Config File
		PB_CORE_INFO("reading config.lua");
		sol::state lua;
		lua.open_libraries(sol::lib::base, sol::lib::os, sol::lib::math);
		sol::unsafe_function_result CodeResult = lua.script_file("./assets/scripts/config.lua", [](lua_State*, sol::protected_function_result pfr) {
			return pfr;
		});

		if (!CodeResult.valid()) {
			PB_CORE_ERROR("Couldn't read config.lua file!");
			exit(1);
		}

		sol::optional<sol::table> config = lua["config"];
		if (config == sol::nullopt) {
			PB_CORE_ERROR("config.lua doesn't have a config table!");
			exit(1);
		}
		
		s_Window = Window::Create(lua["config"]["width"], lua["config"]["height"], lua["config"]["title"]);
		// TODO: Camera should be defined by the client
		s_Camera = { 0, 0, lua["config"]["width"], lua["config"]["height"] };

		PB_CORE_INFO("Finished loading config.lua");
		// TODO: Well, it's having SDL_Window* references here...
		s_Renderer = SDL_CreateRenderer(static_cast<SDL_Window*>(s_Window->GetPlatformSpecificWindow()), -1, 0);
		PB_CORE_ASSERT(s_Renderer, "Could not Create SDL Renderer!");
		PB_CORE_INFO("Created SDL2 Renderer!");

		m_bIsRunning = true;
	}

	void Application::Run() {
		PB_CORE_INFO("Running app!");
		Start();

		s_EManager->BeginPlay();
		while (m_bIsRunning) {
			// Calculating DeltaTime for the current frame
			// TODO: Remove SDL2 dependent code from here
			float DeltaTime = (SDL_GetTicks() - m_TicksLastFrame) / 1000.0f;
			DeltaTime = (DeltaTime > 0.05f) ? 0.05f : DeltaTime;
			m_TicksLastFrame = SDL_GetTicks();

			ProcessInput();
			Update(DeltaTime);
			Render();

			// Sleep execution until target frame time is reached
			// TODO: Remove SDL2 dependent code from here
			int TimeToWait = FRAME_TARGET_TIME - (SDL_GetTicks() - m_TicksLastFrame);
			if (TimeToWait > 0.0f && TimeToWait <= FRAME_TARGET_TIME) {
				SDL_Delay(TimeToWait);
			}
		}

		// Cleaning up
		PB_CORE_INFO("Cleaning up app");
		SDL_DestroyRenderer(s_Renderer);
		delete s_Window;
		SDL_Quit();
	}

	void Application::Start() {

	}

	void Application::ProcessInput() {
		Input::Update();

		if (Input::PlayerPressedExitInput()) {
			m_bIsRunning = false;
		}
	}

	void Application::Update(float DeltaTime) {
		s_EManager->Update(DeltaTime);
		s_ParticleSystem.Update(DeltaTime);
		HandleCameraMovement();
		CheckCollision();
	}

	void Application::HandleCameraMovement() {
		if (m_pTransformToFollow == nullptr) {
			return;
		}

		// TODO: Remove magic numbers from here
		s_Camera.x = m_pTransformToFollow->Position->x - (s_Window->GetWindowWidth() / 2);
		s_Camera.y = m_pTransformToFollow->Position->y - (s_Window->GetWindowHeight() / 2);

		// Clamping camera values
		s_Camera.x = s_Camera.x < 0 ? 0 : s_Camera.x;
		s_Camera.y = s_Camera.y < 0 ? 0 : s_Camera.y;
		s_Camera.x = s_Camera.x > s_Camera.w ? s_Camera.w : s_Camera.x;
		s_Camera.y = s_Camera.y > s_Camera.h ? s_Camera.h : s_Camera.y;
	}

	void Application::CheckCollision() {
		ECollisionType Collision = s_EManager->CheckCollisionOnAllEntities();
	}

	void Application::Render() {
		SDL_SetRenderDrawColor(s_Renderer, 21, 21, 21, 255);
		SDL_RenderClear(s_Renderer);

		
		if (s_EManager->HasEntities()) {
			s_EManager->Render();
		}

		// TODO: Add Layers for Particles just like we have it for entities!
		s_ParticleSystem.Render();

		// Resetting the Render Draw Color because the Particle System messes with it.
		SDL_SetRenderDrawColor(s_Renderer, 21, 21, 21, 255);

		// Swap front and back buffers to render
		SDL_RenderPresent(s_Renderer);
	}
}