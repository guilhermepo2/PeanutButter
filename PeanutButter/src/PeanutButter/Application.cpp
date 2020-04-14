#include "pbpch.h"
#include "Application.h"
#include <SDL.h>

namespace PeanutButter {
	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create(WindowInformation("Peanut Butter Engine", 480, 270)));
		m_bIsRunning = true;
	}

	void Application::Run() {
		while (m_Window->IsWindowValid()) {
			m_Window->Update();
		}

		SDL_Quit();
	}
}