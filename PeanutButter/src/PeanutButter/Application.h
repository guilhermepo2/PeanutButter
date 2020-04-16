#pragma once

#include "Core.h"
#include <SDL.h>
#undef main // dumb SDL stuff

namespace PeanutButter {

	class AssetManager;

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

	protected:
		void ProcessInput();
		void Update();
		void Render();

	private:
		bool m_bIsRunning;
		float m_TicksLastFrame;
	};

	// Defined in the client
	Application* CreateApplication();
}
