#pragma once
#include <SDL.h>
#include "PeanutButter/Entity/EntityManager.h"
#include "TextureManager.h"

#include <map>

namespace PeanutButter {
	class AssetManager {
	public:
		AssetManager(EntityManager* InManager);
		~AssetManager();
		void ClearData();
		void AddTexture(const char* TextureID, const char* Filepath);
		SDL_Texture* GetTexture(const char* TextureID);

	private:
		EntityManager* Manager;
		std::map<const char*, SDL_Texture*> m_Textures;
	};
}