#include "pbpch.h"
#include "Application.h"
#include "PeanutButter/Log.h"
#include "PeanutButter/Utils/AssetManager.h"
#include "PeanutBUtter/Entity/Component/Sprite.h"
#include "PeanutButter/Math/Math.h"

const unsigned int FPS = 60;
const unsigned int FRAME_TARGET_TIME = 1000 / FPS;

namespace PeanutButter {

	EntityManager* Application::s_EManager = new EntityManager();
	bool Application::s_bSDL2Initialized = false;
	SDL_Renderer* Application::s_Renderer = nullptr;
	SDL_Window* Application::s_Window = nullptr;
	SDL_Event Application::ApplicationEvent;
	AssetManager* Application::s_AssetManager = new AssetManager(s_EManager);
	SDL_Rect Application::s_Camera = { 0, 0, 640, 360};

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

		s_Window = SDL_CreateWindow("Peanut Butter Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 360, 0);
		PB_CORE_ASSERT(s_Window, "Could not create SDL2 Window!");
		PB_CORE_INFO("Created SDL2 Window!");

		s_Renderer = SDL_CreateRenderer(s_Window, -1, 0);
		PB_CORE_ASSERT(s_Renderer, "Could not Create SDL Renderer!");
		PB_CORE_INFO("Created SDL2 Renderer!");

		m_bIsRunning = true;
	}

	void Application::Run() {
		PB_CORE_INFO("Running app!");
		Start();

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
		SDL_DestroyWindow(s_Window);
		SDL_Quit();
	}

	void Application::Start() {

	}

	void Application::ProcessInput() {
		SDL_PollEvent(&ApplicationEvent);

		switch (ApplicationEvent.type) {
		case SDL_QUIT:
			m_bIsRunning = false;
			break;
		default:
			break;
		}
	}

	void Application::Update(float DeltaTime) {
		s_EManager->Update(DeltaTime);
		HandleCameraMovement();
		CheckCollision();
	}

	void Application::HandleCameraMovement() {
		if (m_pTransformToFollow == nullptr) {
			return;
		}

		// TODO: Remove magic numbers from here
		s_Camera.x = m_pTransformToFollow->Position->x -320;
		s_Camera.y = m_pTransformToFollow->Position->y - 180;

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

		// Swap front and back buffers to render
		SDL_RenderPresent(s_Renderer);
	}
}