#pragma once

#include "Core.h"

namespace PeanutButter {
	class PB_API Application {
	public:
		Application() {}
		virtual ~Application() {}
		void Run();
	};

	// This is going to be defined in the client.
	Application* CreateApplication();
}

