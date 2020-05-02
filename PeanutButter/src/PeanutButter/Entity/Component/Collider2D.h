#pragma once
#include <SDL.h> // TODO: Remove this from here somehow
#include "PeanutButter/Application.h"
#include "PeanutButter/Entity/Component/Component.h"
#include "PeanutButter/Entity/Component/Transform.h"

namespace PeanutButter {
	class PB_API Collider2D : public Component {
	public:
		const char* ColliderTag;
		SDL_Rect Collider;
		SDL_Rect SourceRectangle;
		SDL_Rect DestinationRectangle;
		Transform* transform;
		Vector2 ColliderSize;

		Collider2D(const char* ColliderTag, Vector2 Position, Vector2 Size) {
			this->ColliderTag = ColliderTag;
			this->Collider = { static_cast<int>(Position.x), static_cast<int>(Position.y), static_cast<int>(Size.x), static_cast<int>(Size.y) };
			this->ColliderSize = Size;
		}

	protected:
		//

	public:

		void Initialize() override {
			if (owner->HasComponentOfType<Transform>()) {
				transform = owner->GetComponentOfType<Transform>();
				SourceRectangle = { 0, 0, static_cast<int>(ColliderSize.x), static_cast<int>(ColliderSize.y) };
				DestinationRectangle = { Collider.x, Collider.y, Collider.w, Collider.h };
			}
		}

		void Update(float DeltaTime) override {
			Collider.x = static_cast<int>(transform->Position->x);
			Collider.y = static_cast<int>(transform->Position->y);
			// TODO: Multiply Collider width and height with the transform scale? Is it needed?
			Collider.w = ColliderSize.x * transform->Scale->x;
			Collider.h = ColliderSize.y * transform->Scale->y;

			DestinationRectangle.x = Collider.x - Application::s_Camera.x;
			DestinationRectangle.y = Collider.y - Application::s_Camera.y;
		}

		void Render() override {}
	};
}
