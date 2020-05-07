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

	void AssetManager::AddTexture(std::string TextureID, std::string Filepath) {
		m_Textures.emplace(TextureID, TextureManager::LoadTexture(Filepath));
	}

	void AssetManager::AddFont(std::string FontID, std::string Filepath, int FontSize) {
		PB_CORE_INFO("Emplacing Font {0} with Filepath {1}", FontID, Filepath);
		m_Fonts.emplace(std::string(FontID), FontManager::LoadFont(Filepath, FontSize));
	}

	SDL_Texture* AssetManager::GetTexture(std::string TextureID) {
		return m_Textures[TextureID];
	}

	TTF_Font* AssetManager::GetFont(std::string FontID) {
		return m_Fonts[FontID];
	}
}