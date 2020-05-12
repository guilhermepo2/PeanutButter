#pragma once
#include <SDL.h>
#include "PeanutButter/Core.h"
#include "PeanutButter/Window.h"

namespace PeanutButter {
	class PB_API SDL2Window : public Window {
	public:
		SDL2Window(int WindowWidth, int WindowHeight, std::string WindowTitle);
		virtual ~SDL2Window();

	protected:
		SDL_Window* m_Window;

	public:
		virtual inline void* GetPlatformSpecificWindow() const { return m_Window; }
		virtual void Destroy() override;
	};
}