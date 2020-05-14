#pragma once

#include "PeanutButter/Input/Input.h"

namespace PeanutButter {
	class PB_API SDL2Input : public Input {
	public:
		SDL2Input();
	protected:
		virtual bool IsKeyPressed_Implementation(PB_Keycode KeyCode) override;
		virtual bool IsMouseButtonPressed_Implementation(PB_Mousecode Button) override;
		virtual std::pair<float, float> GetMousePosition_Implementation() override;
		virtual float GetMouseX_Implementation() override;
		virtual float GetMouseY_Implementation() override;
		virtual void Update_Implementation() override;
		virtual bool PlayerPressedExitInput_Implementation() override;

		const Uint8* m_KeyboardState;
		bool m_bPressedToExit = false;
		std::vector<bool> m_MouseButtons;

	private:
		void OnMouseButtonChanged(const SDL_Event& Event, bool Pressed);
	};
}