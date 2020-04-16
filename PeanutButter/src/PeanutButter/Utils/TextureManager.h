#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "PeanutButter/Application.h"

namespace PeanutButter {
	class PB_API TextureManager {
	public:
		static SDL_Texture* LoadTexture(const char* Filename);
		static void Draw(SDL_Texture* Texture, const SDL_Rect& SourceRectangle, const SDL_Rect& DestinationRectangle, const SDL_RendererFlip& Flip);
	};
}