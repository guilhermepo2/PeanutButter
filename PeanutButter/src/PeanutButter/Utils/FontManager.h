#pragma once
#include <SDL_ttf.h>	
#include "PeanutButter/Application.h"

namespace PeanutButter {
	class FontManager {
	public:
		static TTF_Font* LoadFont(const char* Filepath, int FontSize);
		static void DrawFont(SDL_Texture* Texture, SDL_Rect Position);
	};
}