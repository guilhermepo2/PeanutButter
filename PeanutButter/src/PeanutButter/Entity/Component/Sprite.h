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

		Sprite(std::string Filepath, const Vector2& InSpriteSize) {
			m_bIsAnimated = false;
			SpriteSize = Vector2(InSpriteSize.x, InSpriteSize.y);
			m_SourceRectanglePosition = Vector2(0.0f, 0.0f);

			SetTexture(Filepath);
		}

		Sprite(std::string Filepath, const Vector2& InSpriteSize, const Vector2& InSourceRectangle) {
			m_bIsAnimated = false;
			SpriteSize = Vector2(InSpriteSize.x, InSpriteSize.y);
			m_SourceRectanglePosition = Vector2(InSourceRectangle.x, InSourceRectangle.y);

			SetTexture(Filepath);
		}

		Sprite(std::string Filepath, const Vector2& InSpriteSize, pb_uint8 InNumberOfFrames, pb_uint8 InAnimationSpeed, bool InHasDirection) {
			m_bIsAnimated = true;
			SpriteSize = Vector2(InSpriteSize.x, InSpriteSize.y);
			m_NumberOfFrames = InNumberOfFrames;
			m_AnimationSpeed = InAnimationSpeed;

			if (InHasDirection) {
				Animation DownAnimation = Animation(0, InNumberOfFrames, InAnimationSpeed);
				Animation RightAnimation = Animation(1, InNumberOfFrames, InAnimationSpeed);
				Animation LeftAnimation = Animation(2, InNumberOfFrames, InAnimationSpeed);
				Animation UpAnimation = Animation(3, InNumberOfFrames, InAnimationSpeed);

				m_AnimationList.emplace("DownAnimation", DownAnimation);
				m_AnimationList.emplace("RightAnimation", RightAnimation);
				m_AnimationList.emplace("LeftAnimation", LeftAnimation);
				m_AnimationList.emplace("UpAnimation", UpAnimation);

				m_CurrentAnimationIndex = 0;
				m_CurrentAnimationName = "DownAnimation";
			}
			else {
				m_AnimationList.emplace("SingleAnimation", Animation(0, m_NumberOfFrames, m_AnimationSpeed));
				m_CurrentAnimationIndex = 0;
				this->m_CurrentAnimationName = "SingleAnimation";
			}

			m_SourceRectanglePosition = Vector2(0.0f, 0.0f);
			Play(m_CurrentAnimationName);
			SetTexture(Filepath);
		}

	private:
		Transform* transform;
		SDL_Texture* Texture;
		Vector2 m_SourceRectanglePosition;
		SDL_Rect SourceRectangle;
		SDL_Rect DestinationRectangle;

		// TODO: Animation related stuff should be an AnimatedSprite class
		bool m_bIsAnimated;
		pb_uint8 m_NumberOfFrames;
		pb_uint8 m_AnimationSpeed;
		std::map<std::string, Animation> m_AnimationList;
		pb_uint8 m_CurrentAnimationIndex;
		std::string m_CurrentAnimationName;

	public:
		void Initialize() override {
			transform = owner->GetComponentOfType<Transform>();
			SourceRectangle.x = static_cast<int>(m_SourceRectanglePosition.x);
			SourceRectangle.y = static_cast<int>(m_SourceRectanglePosition.y);
			SourceRectangle.w = static_cast<int>(SpriteSize.x);
			SourceRectangle.h = static_cast<int>(SpriteSize.y);
		}

		void Update(float DeltaTime) override {
			// TODO: Animation should not work like this.
			if (m_bIsAnimated) {
				SourceRectangle.x = SourceRectangle.w * static_cast<int>((SDL_GetTicks() / m_AnimationSpeed) % m_NumberOfFrames);
				SourceRectangle.y = m_CurrentAnimationIndex * static_cast<int>(SpriteSize.y);
			}

			DestinationRectangle.x = static_cast<int>(transform->Position->x) - Application::s_Camera.x;
			DestinationRectangle.y = static_cast<int>(transform->Position->y) - Application::s_Camera.y;
			DestinationRectangle.w = static_cast<int>(SpriteSize.x) * transform->Scale->x;
			DestinationRectangle.h = static_cast<int>(SpriteSize.y) * transform->Scale->y;
		}

		void Render() override {
			// PB_CORE_INFO("Rendering Sprite on Position {0} {1}", transform->Position->x, transform->Position->y);
			TextureManager::Draw(Texture, SourceRectangle, DestinationRectangle, SpriteFlip);
		}

		void Play(std::string AnimationName) {
			m_NumberOfFrames = m_AnimationList[AnimationName].NumberOfFrames;
			m_CurrentAnimationIndex = m_AnimationList[AnimationName].Index;
			m_AnimationSpeed = m_AnimationList[AnimationName].AnimationSpeed;
			m_CurrentAnimationName = AnimationName;
		}

		inline void SetTexture(std::string TextureID) { Texture = Application::s_AssetManager->GetTexture(TextureID); }
	};
}