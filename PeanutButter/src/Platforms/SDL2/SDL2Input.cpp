#include "pbpch.h"
#include "SDL2Input.h"
#include <SDL.h>

namespace PeanutButter {

	Input* Input::s_Instance = new SDL2Input();

	bool SDL2Input::IsKeyPressed_Implementation(int KeyCode) {
		// TODO
		return false;
	}

	bool IsMouseButtonPressed_Implementation(int Button) {
		// TODO
		return false;
	}

	std::pair<float, float> GetMousePosition_Implementation() {
		return std::pair<float, float>(0.0f, 0.0f);
	}

	float GetMouseX_Implementation() {
		// C++17 feature
		auto [x, y] = GetMousePosition_Implementation();
		return x;
	}

	float GetMouseY_Implementation() {
		// C++17 feature
		auto [x, y] = GetMousePosition_Implementation();
		return y;
	}

	void Update_Implementation() {
		SDL_Event FrameEvent;
		if (SDL_PollEvent(&FrameEvent)) {
			switch (FrameEvent.type) {
			case SDL_QUIT:
				break;
			case SDL_MOUSEBUTTONDOWN:
				break;
			case SDL_MOUSEBUTTONUP:
				break;
			case SDL_MOUSEMOTION:
				break;
			}
		}
	};
}