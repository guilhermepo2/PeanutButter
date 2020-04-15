#include "pbpch.h"
#include "Application.h"
#include "PeanutButter/Log.h"
#include <SDL.h>

namespace PeanutButter {

	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create(WindowInformation("Peanut Butter Engine", 480, 270)));
		m_bIsRunning = true;
	}

	Application::Application(const char* WindowTitle, pb_int16 WindowWidth, pb_int16 WindowHeight) {
		m_Window = std::unique_ptr<Window>(Window::Create(WindowInformation(WindowTitle, WindowWidth, WindowHeight)));
		m_bIsRunning = true;
	}

	void Application::Run() {
		while (m_Window->IsWindowValid()) {
			m_Window->Update();
		}
	}
}