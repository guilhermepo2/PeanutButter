#include "pbpch.h"
#include "Application.h"
#include "PeanutButter/Log.h"
#include <SDL.h>

const unsigned int FPS = 60;
const unsigned int FRAME_TARGET_TIME = 1000 / FPS;

namespace PeanutButter {

	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create(WindowInformation("Peanut Butter Engine", 480, 270)));
		m_Renderer = std::unique_ptr<Renderer>(Renderer::Create(m_Window.get()));
		m_bIsRunning = true;
	}

	Application::Application(const char* WindowTitle, pb_int16 WindowWidth, pb_int16 WindowHeight) {
		m_Window = std::unique_ptr<Window>(Window::Create(WindowInformation(WindowTitle, WindowWidth, WindowHeight)));
		m_Renderer = std::unique_ptr<Renderer>(Renderer::Create(m_Window.get()));
		m_bIsRunning = true;
	}

	void Application::Run() {
		while (m_Window->IsWindowValid()) {
			// Calculating DeltaTime for the current frame
			// TODO: Remove SDL2 dependent code from here
			float DeltaTime = (SDL_GetTicks() - m_TicksLastFrame) / 1000.0f;
			DeltaTime = (DeltaTime > 0.05f) ? 0.05f : DeltaTime;
			m_TicksLastFrame = SDL_GetTicks();

			m_Window->Update();
			m_Renderer->Update();

			// Sleep execution until target frame time is reached
			// TODO: Remove SDL2 dependent code from here
			int TimeToWait = FRAME_TARGET_TIME - (SDL_GetTicks() - m_TicksLastFrame);
			if (TimeToWait > 0.0f && TimeToWait <= FRAME_TARGET_TIME) {
				SDL_Delay(TimeToWait);
			}
		}

		m_Renderer.release();
		m_Window.release();
	}
}