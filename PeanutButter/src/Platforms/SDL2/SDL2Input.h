#pragma once

#include "PeanutButter/Input/Input.h"

namespace PeanutButter {
	class PB_API SDL2Input : public Input {
	protected:
		virtual bool IsKeyPressed_Implementation(int KeyCode) override;
		virtual bool IsMouseButtonPressed_Implementation(int Button) override;
		virtual std::pair<float, float> GetMousePosition_Implementation() override;
		virtual float GetMouseX_Implementation() override;
		virtual float GetMouseY_Implementation() override;
	};
}