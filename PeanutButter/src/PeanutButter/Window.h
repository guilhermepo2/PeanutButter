#pragma once
#include "pbpch.h"
#include "PeanutButter/Core.h"

namespace PeanutButter {
	class Window {
	public:
		virtual ~Window() {}

	protected:
		pb_uint16 m_WindowWidth;
		pb_uint16 m_WindowHeight;
		std::string m_WindowTitle;

	public:
		int GetWindowWidth() const { return m_WindowWidth; }
		inline int GetWindowHeight() const { return m_WindowHeight; }
		inline std::string GetWindowTitle() const { return m_WindowTitle; }
		virtual void* GetPlatformSpecificWindow() const = 0;
		virtual void Destroy() = 0;

		// Cannot be named "CreateWindow" because it's a Windows specific function name
		static Window* Create(int WindowWidth, int WindowHeight, std::string WindowTitle);
	};
}