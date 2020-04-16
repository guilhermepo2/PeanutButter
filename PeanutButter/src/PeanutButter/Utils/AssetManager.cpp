#include "pbpch.h"
#include "AssetManager.h"


namespace PeanutButter {
	AssetManager::AssetManager(EntityManager* InManager) : Manager(InManager) {

	}
	
	void AssetManager::ClearData() {
		m_Textures.clear();
	}

	void AssetManager::AddTexture(const char* TextureID, const char* Filepath) {
		m_Textures.emplace(TextureID, TextureManager::LoadTexture(Filepath));
	}

	SDL_Texture* AssetManager::GetTexture(const char* TextureID) {
		return m_Textures[TextureID];
	}
}