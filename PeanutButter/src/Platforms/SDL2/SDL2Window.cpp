#include "pbpch.h"
#include "SDL2Window.h"
#include "PeanutButter/Log.h"

namespace PeanutButter {
	Window* Window::Create(int WindowWidth, int WindowHeight, std::string WindowTitle) {
		return new SDL2Window(WindowWidth, WindowHeight, WindowTitle);
	}

	SDL2Window::SDL2Window(int WindowWidth, int WindowHeight, std::string WindowTitle) {
		pb_uint32 WasInitialized = SDL_WasInit(SDL_INIT_EVERYTHING);

		PB_CORE_ASSERT(WasInitialized, "SDL was not initialized before creating a window")
		m_Window = SDL_CreateWindow(WindowTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WindowWidth, WindowHeight, 0);
		PB_CORE_ASSERT(s_Window, "Could not create SDL2 Window!");
		PB_CORE_INFO("Created SDL2 Window!");
	}

	SDL2Window::~SDL2Window() {
		Destroy();
	}
	
	void SDL2Window::Destroy() {
		SDL_DestroyWindow(m_Window);
	}
}