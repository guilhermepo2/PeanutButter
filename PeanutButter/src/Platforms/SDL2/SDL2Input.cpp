#include "pbpch.h"
#include "PeanutButter/Log.h"
#include "SDL2Input.h"
#include <SDL.h>

namespace PeanutButter {

	Input* Input::s_Instance = new SDL2Input();

	SDL2Input::SDL2Input() {
		for (int i = 0; i < PB_MOUSE_BUTTON_AMOUNT; i++) {
			m_MouseButtons.push_back(false);
		}
	}

	// TODO: In Parameter should be a "SDL_Scancode"
	bool SDL2Input::IsKeyPressed_Implementation(PB_Keycode KeyCode) {
		if (m_KeyboardState != nullptr) {
			if (m_KeyboardState[KeyCode] == 1) {
				return true;
			}
		}

		return false;
	}

	bool SDL2Input::IsMouseButtonPressed_Implementation(PB_Mousecode Button) {
		return m_MouseButtons[Button];
	}

	std::pair<float, float> SDL2Input::GetMousePosition_Implementation() {
		return std::pair<float, float>(m_MousePositionX, m_MousePositionY);
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
				OnMouseButtonChanged(FrameEvent, true);
				break;
			case SDL_MOUSEBUTTONUP:
				OnMouseButtonChanged(FrameEvent, false);
				break;
			case SDL_MOUSEMOTION:
				OnMouseMoved(FrameEvent);
				break;
			}
		}
	}

	bool SDL2Input::PlayerPressedExitInput_Implementation() {
		return m_bPressedToExit;
	}

	void SDL2Input::OnMouseButtonChanged(const SDL_Event& Event, bool Pressed) {
		if (Event.button.button == SDL_BUTTON_LEFT) {
			m_MouseButtons[PB_MOUSECODE_LEFT] = Pressed;
		}
		else if (Event.button.button == SDL_BUTTON_MIDDLE) {
			m_MouseButtons[PB_MOUSECODE_MIDDLE] = Pressed;
		}
		else if (Event.button.button == SDL_BUTTON_RIGHT) {
			m_MouseButtons[PB_MOUSECODE_RIGHT] = Pressed;
		}
	}

	void SDL2Input::OnMouseMoved(const SDL_Event& Event) {
		m_MousePositionX = Event.motion.x;
		m_MousePositionY = Event.motion.y;
	}
}