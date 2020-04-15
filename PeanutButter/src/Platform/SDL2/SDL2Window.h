#pragma once
#include "PeanutButter/Log.h"
#include "PeanutButter/Window.h"
#include <SDL.h>

namespace PeanutButter {
	/**
	* Implementation of a SDL2 Window
	*/
	class SDL2Window : public Window {
	public:
		SDL2Window(const WindowInformation& Info);
		virtual ~SDL2Window();

	protected:
		virtual void Initialize(const WindowInformation& Info);
		virtual void Destroy();

	protected:
		SDL_Window* m_pWindow;
		
		struct WindowData {
			std::string Title;
			pb_uint16 Width;
			pb_uint16 Height;
			CallbackFunction EventCallback;
		};

		WindowData m_Data;

	public:
		void Update() override;
		inline pb_uint16 GetWidth() const override { return m_Data.Width; }
		inline pb_uint16 GetHeight() const override { return m_Data.Height; }
		inline void SetCallback(const CallbackFunction& Callback) { m_Data.EventCallback = Callback; }
		inline bool IsWindowValid() const override { return m_pWindow != nullptr; }
		inline SDL_Window* GetSDLWindow() const { return m_pWindow; }
	};
}

