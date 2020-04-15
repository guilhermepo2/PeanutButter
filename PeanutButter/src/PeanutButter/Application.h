#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace PeanutButter {
	class PB_API Application {
	public:
		Application();
		virtual ~Application() {}
		void Run();

		void OnEvent(Event& InEvent);

	protected:
		std::unique_ptr<Window> m_Window;
		bool m_bIsRunning;
	};

	// This is going to be defined in the client.
	Application* CreateApplication();
}

