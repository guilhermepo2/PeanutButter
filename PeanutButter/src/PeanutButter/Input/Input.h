#pragma once
#include "PeanutButter/Core.h"

namespace PeanutButter {
	class PB_API Input {
	public:
		inline static bool IsKeyPressed(int KeyCode) { return s_Instance->IsKeyPressed_Implementation(KeyCode); }
		inline static bool IsMouseButtonPressed(int Button) { return s_Instance->IsMouseButtonPressed_Implementation(Button); }
		inline static std::pair<float, float> GetMousePosition() { return s_Instance->GetMousePosition_Implementation(); }
		inline static float GetMouseX() { return s_Instance->GetMouseX_Implementation(); }
		inline static float GetMouseY() { return s_Instance->GetMouseY_Implementation(); }


	/*
	* The protected functions is what is actually implemented in the platforms. 
	*/
	protected:


		virtual bool IsKeyPressed_Implementation(int KeyCode) = 0;
		virtual bool IsMouseButtonPressed_Implementation(int Button) = 0;
		virtual std::pair<float, float> GetMousePosition_Implementation() = 0;
		virtual float GetMouseX_Implementation() = 0;
		virtual float GetMouseY_Implementation() = 0;

	private:
		static Input* s_Instance;
	};
}