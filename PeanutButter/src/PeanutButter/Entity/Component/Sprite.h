#pragma once
#include <SDL.h>
#include "PeanutButter/Utils/AssetManager.h"
#include "PeanutButter/Entity/Component/Component.h"
#include "PeanutButter/Entity/Component/Transform.h"
#include "PeanutButter/Application.h"
#include "PeanutButter/Math/Math.h"

namespace PeanutButter {
	class PB_API Sprite : public Component {
	public:
		SDL_RendererFlip SpriteFlip = SDL_FLIP_NONE;
		Vector2 SpriteSize;

		Sprite(const char* Filepath, const Vector2& InSpriteSize) {
			SetTexture(Filepath);
			SpriteSize = Vector2(InSpriteSize.x, InSpriteSize.y);
		}

	private:
		Transform* transform;
		SDL_Texture* Texture;
		SDL_Rect SourceRectangle;
		SDL_Rect DestinationRectangle;

	public:
		void Initialize() override {
			transform = owner->GetComponentOfType<Transform>();
			SourceRectangle.x = 0;
			SourceRectangle.y = 0;
			SourceRectangle.w = static_cast<int>(SpriteSize.x);
			SourceRectangle.h = static_cast<int>(SpriteSize.y);
		}

		void Update(float DeltaTime) override {
			DestinationRectangle.x = static_cast<int>(transform->Position->x);
			DestinationRectangle.y = static_cast<int>(transform->Position->y);
			DestinationRectangle.w = static_cast<int>(SpriteSize.x) * static_cast<int>(transform->Scale->x);
			DestinationRectangle.h = static_cast<int>(SpriteSize.y) * static_cast<int>(transform->Scale->y);
		}

		void Render() override {
			// PB_CORE_INFO("Rendering Sprite on Position {0} {1}", transform->Position->x, transform->Position->y);
			TextureManager::Draw(Texture, SourceRectangle, DestinationRectangle, SpriteFlip);
		}

		inline void SetTexture(const char* TextureID) { Texture = Application::s_AssetManager->GetTexture(TextureID); }
	};
}