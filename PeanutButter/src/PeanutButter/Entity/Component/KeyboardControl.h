#pragma once
#include "PeanutButter/Input/Input.h"
#include "PeanutButter/Entity/Component/Component.h"
#include "PeanutButter/Entity/Component/Sprite.h"
#include "PeanutButter/Entity/Component/Transform.h"

namespace PeanutButter {
	class PB_API KeyboardControl : public Component {
	public:
		Transform* transform;
		Sprite* sprite;

		KeyboardControl() {}

		void Initialize() override {
			transform = owner->GetComponentOfType<Transform>();
			sprite = owner->GetComponentOfType<Sprite>();
		}

		void Update(float DeltaTime) override {
			if (Input::IsKeyPressed(PB_KEYCODE_W)) {
				transform->Position->y -= 1;
				sprite->Play("UpAnimation");
			}

			if (Input::IsKeyPressed(PB_KEYCODE_S)) {
				transform->Position->y += 1;
				sprite->Play("DownAnimation");
			}

			if (Input::IsKeyPressed(PB_KEYCODE_D)) {
				transform->Position->x += 1;
				sprite->Play("RightAnimation");
			}

			if (Input::IsKeyPressed(PB_KEYCODE_A)) {
				transform->Position->x -= 1;
				sprite->Play("LeftAnimation");
			}
		}

		void Render() override {}
	};
}