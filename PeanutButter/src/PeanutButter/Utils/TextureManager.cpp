#include "pbpch.h"
#include "PeanutButter/Log.h"
#include "TextureManager.h"

namespace PeanutButter {
	SDL_Texture* TextureManager::LoadTexture(const char* Filename) {
		SDL_Surface* Surface = IMG_Load(Filename);
		
		if (Surface == nullptr) {
			PB_CORE_ERROR("Couldn't load image on path {0} - Error: {1}", Filename, IMG_GetError());
		}

		SDL_Texture* Texture = SDL_CreateTextureFromSurface(Application::s_Renderer, Surface);
		SDL_FreeSurface(Surface);
		return Texture;
	}

	void TextureManager::Draw(SDL_Texture* Texture, const SDL_Rect& SourceRectangle, const SDL_Rect& DestinationRectangle, const SDL_RendererFlip& Flip) {
		SDL_RenderCopyEx(Application::s_Renderer, Texture, &SourceRectangle, &DestinationRectangle, 0.0, nullptr, Flip);
	}
}