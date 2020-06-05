#pragma once
#include <SDL_ttf.h>
#include "PeanutButter/Entity/Component/Component.h"
#include "PeanutButter/Application.h"
#include "PeanutButter/Utils/AssetManager.h"
#include "PeanutButter/Entity/EntityManager.h"
#include "PeanutButter/Utils/FontManager.h"

namespace PeanutButter {
	class UIText : public Component {
	public:
		UIText(Vector2 Position, std::string InText, std::string InFontFamily, const SDL_Color InColor) {
			m_Position.x = static_cast<int>(Position.x);
			m_Position.y = static_cast<int>(Position.y);
			Text = InText;
			FontFamily = InFontFamily;
			Color = InColor;
			m_Texture = nullptr;
			SetLabelText(InText, InFontFamily);
		}

	private:
		SDL_Rect m_Position;
		std::string Text;
		std::string FontFamily;
		SDL_Color Color;
		SDL_Texture* m_Texture;

	public:
		void SetLabelText(std::string Text, std::string FontFamily) {
			TTF_Font* FontFile = Application::s_AssetManager->GetFont(FontFamily.c_str());

			if (FontFile == nullptr) {
				PB_CORE_WARNING("Error Loading the Font {0}, Text element won't work.", FontFamily);
				return;
			}

			SDL_Surface* Surface = TTF_RenderText_Blended(FontFile, Text.c_str(), Color);
			m_Texture = SDL_CreateTextureFromSurface(Application::s_Renderer, Surface);
			SDL_FreeSurface(Surface);
			SDL_QueryTexture(m_Texture, nullptr, nullptr, &m_Position.w, &m_Position.h);
		}

		void UpdateLabelText(std::string Text) {
			SetLabelText(Text, this->FontFamily);
		}

		void Initialize() override {}
		void Update(float DeltaTime) override {}

		void Render() override {
			FontManager::DrawFont(m_Texture, m_Position);
		}
	};
}