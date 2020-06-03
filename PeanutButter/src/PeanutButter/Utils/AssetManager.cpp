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
		if (m_Textures.count(TextureID) == 0) {
			PB_CORE_ERROR("Couldn't find the texture: {0}", TextureID);
			return nullptr;
		}

		return m_Textures[TextureID];
	}

	TTF_Font* AssetManager::GetFont(std::string FontID) {
		if (m_Fonts.count(FontID) == 0) {
			PB_CORE_ERROR("Couldn't find the font: {0}", FontID);
			return nullptr;
		}

		return m_Fonts[FontID];
	}
}