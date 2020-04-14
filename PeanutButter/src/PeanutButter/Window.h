#pragma once

#include "pbpch.h"
#include "PeanutButter/Core.h"
#include "PeanutButter/Events/Event.h"

namespace PeanutButter {
	struct WindowInformation {
		std::string WindowTitle;
		pb_uint16 Width;
		pb_uint16 Height;

		WindowInformation(const std::string& InTitle = "Peanut Butter", pb_uint16 InWidth = 1280, pb_uint16 InHeight = 720)
			: WindowTitle(InTitle), Width(InWidth), Height(InHeight) {}
	};

	/**
	* The Window Class is a platform-independent abstraction used to create a Window
	* It will further be implemented for every platform (SDL2, GLFW, DirectX, Vulkan, Metal, etc...)
	*/
	class PB_API Window {
	public:
		/** Callback Function: returns void and receive an Event */
		using CallbackFunction = std::function<void(Event&)>;

		virtual ~Window() {}
		virtual void Update() = 0;
		virtual pb_uint16 GetWidth() const = 0;
		virtual pb_uint16 GetHeight() const = 0;
		virtual bool IsWindowValid() const = 0;
		virtual void SetCallback(const CallbackFunction& Callback) = 0;

		// TODO: Set/Get VSync stuff (is it really necessary?)
		// Cannot be named "CreateWindow" because it's a Windows specific function name.
		static Window* Create(const WindowInformation& Info = WindowInformation());
	};
}