#include "pbpch.h"
#include "FontManager.h"
#include "PeanutButter/Log.h"
#include <SDL.h>

namespace PeanutButter {
	TTF_Font* FontManager::LoadFont(std::string Filepath, int FontSize) {
		PB_CORE_INFO("Loading font on path {0}", Filepath);

		TTF_Font* FontLoaded = TTF_OpenFont(Filepath.c_str(), FontSize);

		if (FontLoaded == nullptr) {
			PB_CORE_ERROR("Could not load font!");
		}

		return FontLoaded;
	}

	void FontManager::DrawFont(SDL_Texture* Texture, SDL_Rect Position) {
		SDL_RenderCopy(Application::s_Renderer, Texture, nullptr, &Position);
	}
}