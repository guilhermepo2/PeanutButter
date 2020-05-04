#include "pbpch.h"
#include "AssetManager.h"
#include "PeanutButter/Log.h"

namespace PeanutButter {
	AssetManager::AssetManager(EntityManager* InManager) : Manager(InManager) {

	}
	
	void AssetManager::ClearData() {
		m_Textures.clear();
		m_Fonts.clear();
	}

	void AssetManager::AddTexture(const char* TextureID, const char* Filepath) {
		m_Textures.emplace(TextureID, TextureManager::LoadTexture(Filepath));
	}

	void AssetManager::AddFont(const char* FontID, const char* Filepath, int FontSize) {
		PB_CORE_INFO("Emplacing Font {0} with Filepath {1}", FontID, Filepath);
		m_Fonts.emplace(std::string(FontID), FontManager::LoadFont(Filepath, FontSize));
	}

	SDL_Texture* AssetManager::GetTexture(const char* TextureID) {
		return m_Textures[TextureID];
	}

	TTF_Font* AssetManager::GetFont(const char* FontID) {
		return m_Fonts[FontID];
	}
}