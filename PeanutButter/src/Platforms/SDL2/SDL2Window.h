#pragma once
#include "PeanutButter/Window.h"

namespace PeanutButter {
	class SDL2Window : public Window {
	public:
		SDL2Window(pb_uint16 WindowWidth, pb_uint16 WindowHeight, std::string WindowTitle) : Window(WindowWidth, WindowHeight, WindowTitle) {}
		~SDL2Window() {
		
		}

	protected:
	};
}