#pragma once
#include "KeyboardInput.h"
#include "MouseInput.h"
#include "PeanutButter/Core.h"

namespace PeanutButter {
	class PB_API Input {
	public:
		inline static bool IsKeyPressed				(PB_Keycode KeyCode) { return s_Instance->IsKeyPressed_Implementation(KeyCode); }
		inline static bool WasKeyPressedThisFrame	(PB_Keycode KeyCode) { return s_Instance->IsKeyPressed_Implementation(KeyCode); }
		inline static bool WasKeyReleasedThisFrame	(PB_Keycode KeyCode) { return s_Instance->IsKeyPressed_Implementation(KeyCode); }

		inline static bool IsMouseButtonPressed				(PB_Mousecode Button) { return s_Instance->IsMouseButtonPressed_Implementation(Button);				}
		inline static bool WasMouseButtonPressedThisFrame	(PB_Mousecode Button) { return s_Instance->WasMouseButtonPressedThisFrame_Implementation(Button);	}
		inline static bool WasMouseButtonReleasedThisFrame	(PB_Mousecode Button) { return s_Instance->WasMouseButtonReleasedThisFrame_Implementation(Button);  }

		inline static std::pair<float, float> GetMousePosition() { return s_Instance->GetMousePosition_Implementation(); }
		inline static float GetMouseX() { return s_Instance->GetMouseX_Implementation(); }
		inline static float GetMouseY() { return s_Instance->GetMouseY_Implementation(); }
		inline static void	Update()	{ s_Instance->Update_Implementation();			 }

		// TODO: The application will check this to see if the game should be exited
		// Which is bad, ideally when the exit key is pressed, the input module should tell the application through a delegate, or a function pointer.
		inline static bool PlayerPressedExitInput() { return s_Instance->PlayerPressedExitInput_Implementation(); }

	/*
	* The protected functions is what is actually implemented in the platforms. 
	*/
	protected:
		virtual bool IsKeyPressed_Implementation			(PB_Keycode KeyCode) = 0;
		virtual bool WasKeyPressedThisFrame_Implementation	(PB_Keycode KeyCode) = 0;
		virtual bool WasKeyReleasedThisFrame_Implementation	(PB_Keycode KeyCode) = 0;

		virtual bool IsMouseButtonPressed_Implementation			(PB_Mousecode Button) = 0;
		virtual bool WasMouseButtonPressedThisFrame_Implementation	(PB_Mousecode Button) = 0;
		virtual bool WasMouseButtonReleasedThisFrame_Implementation	(PB_Mousecode Button) = 0;

		virtual std::pair<float, float> GetMousePosition_Implementation() = 0;
		virtual float GetMouseX_Implementation() = 0;
		virtual float GetMouseY_Implementation() = 0;
		virtual void Update_Implementation() = 0;
		virtual bool PlayerPressedExitInput_Implementation() = 0;

	private:
		static Input* s_Instance;
	};
}