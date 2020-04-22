#pragma once
#include <SDL.h>
#include "PeanutButter/Utils/AssetManager.h"
#include "PeanutButter/Entity/Component/Component.h"
#include "PeanutButter/Entity/Component/Transform.h"
#include "PeanutButter/Application.h"
#include "PeanutButter/Math/Math.h"

#include "PeanutButter/Utils/Animation.h"

namespace PeanutButter {
	class PB_API Sprite : public Component {
	public:
		SDL_RendererFlip SpriteFlip = SDL_FLIP_NONE;
		Vector2 SpriteSize;

		Sprite(const char* Filepath, const Vector2& InSpriteSize) {
			m_bIsAnimated = false;
			SetTexture(Filepath);
			SpriteSize = Vector2(InSpriteSize.x, InSpriteSize.y);
		}

		Sprite(const char* Filepath, const Vector2& InSpriteSize, pb_uint8 InNumberOfFrames, pb_uint8 InAnimationSpeed) {
			m_bIsAnimated = true;
			SpriteSize = Vector2(InSpriteSize.x, InSpriteSize.y);
			m_NumberOfFrames = InNumberOfFrames;
			m_AnimationSpeed = InAnimationSpeed;

			// TODO: Have Animation in its own component and have a better interface for adding and playing animations
			m_AnimationList.emplace("SingleAnimation", Animation(0, m_NumberOfFrames, m_AnimationSpeed));
			m_CurrentAnimationIndex = 0;
			Play("SingleAnimation");
			SetTexture(Filepath);
		}

	private:
		Transform* transform;
		SDL_Texture* Texture;
		SDL_Rect SourceRectangle;
		SDL_Rect DestinationRectangle;

		bool m_bIsAnimated;
		pb_uint8 m_NumberOfFrames;
		pb_uint8 m_AnimationSpeed;
		std::map<const char*, Animation> m_AnimationList;
		pb_uint8 m_CurrentAnimationIndex;
		const char* m_CurrentAnimationName;

		void Play(const char* AnimationName) {
			m_NumberOfFrames = m_AnimationList[AnimationName].NumberOfFrames;
			m_CurrentAnimationIndex = m_AnimationList[AnimationName].Index;
			m_AnimationSpeed = m_AnimationList[AnimationName].AnimationSpeed;
			m_CurrentAnimationName = AnimationName;
		}

	public:
		void Initialize() override {
			transform = owner->GetComponentOfType<Transform>();
			SourceRectangle.x = 0;
			SourceRectangle.y = 0;
			SourceRectangle.w = static_cast<int>(SpriteSize.x);
			SourceRectangle.h = static_cast<int>(SpriteSize.y);
		}

		void Update(float DeltaTime) override {
			if (m_bIsAnimated) {
				SourceRectangle.x = SourceRectangle.w * static_cast<int>((SDL_GetTicks() / m_AnimationSpeed) % m_NumberOfFrames);
			}
			SourceRectangle.y = m_CurrentAnimationIndex * static_cast<int>(SpriteSize.y);

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