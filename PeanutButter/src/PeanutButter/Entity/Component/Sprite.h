#pragma once
#include <SDL.h>
#include "PeanutButter/Entity/Component/Component.h"
#include "PeanutButter/Entity/Component/Transform.h"
#include "PeanutButter/Application.h"
#include "PeanutButter/Math/Math.h"

namespace PeanutButter {
	class Sprite : public Component {
	public:
		SDL_RendererFlip SpriteFlip = SDL_FLIP_NONE;
		Vector2 SpriteSize;

		Sprite(const char* Filepath, const Vector2& InSpriteSize) {
			SetTexture(Filepath);
			SpriteSize = InSpriteSize;
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
			SourceRectangle.w = SpriteSize.x;
			SourceRectangle.h = SpriteSize.y;
		}

		void Update(float DeltaTime) override {
			DestinationRectangle.x = static_cast<int>(transform->Position.x);
			DestinationRectangle.y = static_cast<int>(transform->Position.y);
			DestinationRectangle.w = static_cast<int>(SpriteSize.x) * static_cast<int>(transform->Scale.x);
			DestinationRectangle.h = static_cast<int>(SpriteSize.y) * static_cast<int>(transform->Scale.y);
			// PB_CORE_INFO("Sprite Scale: ({0}, {1})", transform->Scale.x, transform->Scale.y);
		}

		void Render() override {
			// PB_CORE_INFO("Rendering Sprite on Position {0} {1}", transform->Position.x, transform->Position.y);
			TextureManager::Draw(Texture, SourceRectangle, DestinationRectangle, SpriteFlip);
		}

		inline void SetTexture(const char* TextureID) { Texture = Application::s_AssetManager->GetTexture(TextureID); }
	};
}