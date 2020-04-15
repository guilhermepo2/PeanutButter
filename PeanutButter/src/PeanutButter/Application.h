#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"
#include "Renderer/Renderer.h"

namespace PeanutButter {
	class PB_API Application {
	public:
		Application();
		Application(const char* WindowTitle, pb_int16 WindowWidth, pb_int16 WindowHeight);
		virtual ~Application() {}
		void Run();

	private:
		std::unique_ptr<Window> m_Window;
		std::unique_ptr<Renderer> m_Renderer;
		bool m_bIsRunning;
	};

	// Defined in the client
	Application* CreateApplication();
}

