#pragma once

#include <SDL.h>
#include "PeanutButter/Renderer/Renderer.h"

namespace PeanutButter {
	class SDL2Renderer : public Renderer {
	public:
		SDL2Renderer(Window* RendererWindow);
		virtual ~SDL2Renderer();
		void Update() override;

	protected:
		void Initialize(Window* RendererWindow);
		void Destroy();

	private:
		SDL_Window* m_WindowReference;
		SDL_Renderer* m_Renderer;
	};
}

