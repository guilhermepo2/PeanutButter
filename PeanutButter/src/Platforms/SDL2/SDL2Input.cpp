#include "pbpch.h"
#include "PeanutButter/Log.h"
#include "SDL2Input.h"
#include <SDL.h>

namespace PeanutButter {

	Input* Input::s_Instance = new SDL2Input();

	// TODO: In Parameter should be a "SDL_Scancode"
	bool SDL2Input::IsKeyPressed_Implementation(PB_Keycode KeyCode) {
		if (m_KeyboardState != nullptr) {
			if (m_KeyboardState[KeyCode] == 1) {
				return true;
			}
		}

		return false;
	}

	bool SDL2Input::IsMouseButtonPressed_Implementation(int Button) {
		// TODO
		return false;
	}

	std::pair<float, float> SDL2Input::GetMousePosition_Implementation() {
		return std::pair<float, float>(0.0f, 0.0f);
	}

	float SDL2Input::GetMouseX_Implementation() {
		// C++17 feature
		auto [x, y] = GetMousePosition_Implementation();
		return x;
	}

	float SDL2Input::GetMouseY_Implementation() {
		// C++17 feature
		auto [x, y] = GetMousePosition_Implementation();
		return y;
	}

	void SDL2Input::Update_Implementation() {
		// PB_CORE_INFO("SDL2 Input: Updating");
		m_KeyboardState = SDL_GetKeyboardState(nullptr);

		SDL_Event FrameEvent;
		if (SDL_PollEvent(&FrameEvent)) {
			switch (FrameEvent.type) {
			case SDL_QUIT:
				m_bPressedToExit = true;
				break;
			case SDL_MOUSEBUTTONDOWN:
				break;
			case SDL_MOUSEBUTTONUP:
				break;
			case SDL_MOUSEMOTION:
				break;
			}
		}
	}

	bool SDL2Input::PlayerPressedExitInput_Implementation() {
		return m_bPressedToExit;
	}
}