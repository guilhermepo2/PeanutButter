#pragma once

#include "Core.h"
#include <SDL.h>
#undef main // dumb SDL stuff

namespace PeanutButter {

	class AssetManager;
	class EntityManager;

	class PB_API Application {
	public:
		Application();
		virtual ~Application() {}
		void Run();

		static bool s_bSDL2Initialized;
		static SDL_Renderer* s_Renderer;
		static SDL_Window* s_Window;
		static SDL_Event ApplicationEvent;
		static AssetManager* s_AssetManager;
		static EntityManager* s_EManager;

	protected:
		virtual void Start();
		void ProcessInput();
		void Update(float DeltaTime);
		void Render();

	private:
		void Initialize();
		bool m_bIsRunning;
		float m_TicksLastFrame;
	};

	// Defined in the client
	Application* CreateApplication();
}
