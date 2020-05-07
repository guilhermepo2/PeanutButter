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
		std::map<std::string, SDL_Texture*> m_Textures;
		std::map<std::string, TTF_Font*> m_Fonts;

	public:
		void ClearData();
		void AddTexture(std::string TextureID, std::string Filepath);
		void AddFont(std::string FontID, std::string Filepath, int FontSize);
		SDL_Texture* GetTexture(std::string TextureID);
		TTF_Font* GetFont(std::string FontID);
	};
}