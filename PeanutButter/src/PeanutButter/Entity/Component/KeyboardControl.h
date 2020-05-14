#pragma once
#include "PeanutButter/Input/Input.h"
#include "PeanutButter/Entity/Component/Component.h"
#include "PeanutButter/Entity/Component/Sprite.h"
#include "PeanutButter/Entity/Component/Transform.h"

namespace PeanutButter {
	class PB_API KeyboardControl : public Component {
	public:
		std::string UpKey;
		std::string RightKey;
		std::string DownKey;
		std::string LeftKey;
		Transform* transform;
		Sprite* sprite;

		KeyboardControl() {}
		KeyboardControl(std::string InUpKey, std::string InRightKey, std::string InDownKey, std::string InLeftKey) {
			this->UpKey = GetSDLKeyStringCode(std::string(InUpKey));
			this->RightKey = GetSDLKeyStringCode(std::string(InRightKey));
			this->DownKey = GetSDLKeyStringCode(std::string(InDownKey));
			this->LeftKey = GetSDLKeyStringCode(std::string(InLeftKey));
		}

		std::string GetSDLKeyStringCode(std::string Key) {
			if (Key.compare("up") == 0) {
				return "1073741906";
			}

			if (Key.compare("down") == 0) {
				return "1073741905";
			}

			if (Key.compare("left") == 0) {
				return "1073741904";
			}

			if (Key.compare("right") == 0) {
				return "1073741903";
			}

			if (Key.compare("space") == 0) {
				return "32";
			}

			return std::to_string(static_cast<int>(Key[0]));
		}

		void Initialize() override {
			transform = owner->GetComponentOfType<Transform>();
			sprite = owner->GetComponentOfType<Sprite>();
		}

		void Update(float DeltaTime) override {
			if (Input::IsKeyPressed(SDL_SCANCODE_W)) {
				transform->Position->y -= 1;
				sprite->Play("UpAnimation");
			}

			if (Input::IsKeyPressed(SDL_SCANCODE_S)) {
				transform->Position->y += 1;
				sprite->Play("DownAnimation");
			}

			if (Input::IsKeyPressed(SDL_SCANCODE_D)) {
				transform->Position->x += 1;
				sprite->Play("RightAnimation");
			}

			if (Input::IsKeyPressed(SDL_SCANCODE_A)) {
				transform->Position->x -= 1;
				sprite->Play("LeftAnimation");
			}
		}

		void Render() override {}
	};
}