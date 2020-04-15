#include "pbpch.h"
#include "SDL2Window.h"

namespace PeanutButter {
	static bool s_bSDL2Initialized = false;

	Window* Window::Create(const WindowInformation& Info) {
		return new SDL2Window(Info);
	}

	SDL2Window::SDL2Window(const WindowInformation& Info) {
		Initialize(Info);
	}

	SDL2Window::~SDL2Window() {
		Destroy();
	}

	void SDL2Window::Initialize(const WindowInformation& Info) {
		m_Data.Title = Info.WindowTitle;
		m_Data.Width = Info.Width;
		m_Data.Height = Info.Height;

		PB_CORE_INFO("Creating Window: {0} ({1}, {2})", Info.WindowTitle, Info.Width, Info.Height);

		if (!s_bSDL2Initialized) {
			int Success = SDL_Init(SDL_INIT_EVERYTHING);
			PB_CORE_ASSERT(Success, "Could not initialize SDL2!");
			PB_CORE_WARNING("Initialized SDL2");
			s_bSDL2Initialized = true;
		}

		m_pWindow = SDL_CreateWindow(Info.WindowTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Info.Width, Info.Height, 0);
		PB_CORE_ASSERT(m_pWindow, "Could not create SDL2 Window!")
		PB_CORE_INFO("Created SDL2 Window");
	}

	void SDL2Window::Destroy() {
		PB_CORE_WARNING("Destroying Window");
		SDL_DestroyWindow(m_pWindow);

		// Don't Quit - Maybe we have multiple windows? 
		SDL_Quit();
	}

	void SDL2Window::Update() {

		// TODO Have a function dedicated to polling events
		// Polling Events
		SDL_Event InputEvent;
		SDL_PollEvent(&InputEvent);
		
		switch (InputEvent.type) {
		case SDL_QUIT:
			// TODO: Call Window Close callback
			PB_CORE_INFO("Closing Window!");
			Destroy();
			break;
		}
	}
}
