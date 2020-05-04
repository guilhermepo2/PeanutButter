#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include "PeanutButter/Entity/EntityManager.h"
#include "TextureManager.h"
#include "FontManager.h"

#include <map>

namespace PeanutButter {
	class PB_API AssetManager {
	public:
		AssetManager(EntityManager* InManager);
		~AssetManager();

	private:
		EntityManager* Manager;
		std::map<const char*, SDL_Texture*> m_Textures;
		std::map<std::string, TTF_Font*> m_Fonts;

	public:
		void ClearData();
		void AddTexture(const char* TextureID, const char* Filepath);
		void AddFont(const char* FontID, const char* Filepath, int FontSize);
		SDL_Texture* GetTexture(const char* TextureID);
		TTF_Font* GetFont(const char* FontID);
	};
}