#include "pbpch.h"
#include "SDL2Renderer.h"
#include "SDL2Window.h"

namespace PeanutButter {
	// TODO Make this more modular
	Renderer* Renderer::Create(Window* RendererWindow) {
		return new SDL2Renderer(RendererWindow);
	}

	SDL2Renderer::SDL2Renderer(Window* RendererWindow) {
		Initialize(RendererWindow);
	}

	void SDL2Renderer::Initialize(Window* RendererWindow) {
		SDL2Window* Window = dynamic_cast<SDL2Window*>(RendererWindow);
		PB_CORE_ASSERT(Window, "Window is not a SDL2 Window!");

		m_WindowReference = Window->GetSDLWindow();
		m_Renderer = SDL_CreateRenderer(m_WindowReference, -1, 0);

		PB_CORE_ASSERT(m_Renderer, "Cannot Create Renderer!");
		PB_CORE_INFO("Renderer created successfuly");
	}

	SDL2Renderer::~SDL2Renderer() {
		Destroy();
	}

	void SDL2Renderer::Destroy() {
		PB_CORE_WARNING("Destroying SDL2 Renderer");
		SDL_DestroyRenderer(m_Renderer);
	}

	void SDL2Renderer::Update() {
		SDL_SetRenderDrawColor(m_Renderer, 21, 21, 21, 255);
		SDL_RenderClear(m_Renderer);
		SDL_RenderPresent(m_Renderer);
	}
}
