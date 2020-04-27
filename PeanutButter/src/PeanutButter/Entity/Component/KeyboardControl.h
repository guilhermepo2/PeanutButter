#pragma once
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
		KeyboardControl(const char* InUpKey, const char* InRightKey, const char* InDownKey, const char* InLeftKey) {
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
			if (Application::ApplicationEvent.type == SDL_KEYDOWN) {
				std::string KeyCode = std::to_string(Application::ApplicationEvent.key.keysym.sym);
				if (KeyCode.compare(UpKey) == 0) {
					transform->Position->y -= 1;
					sprite->Play("UpAnimation");
				}

				if (KeyCode.compare(RightKey) == 0) {
					transform->Position->x += 1;
					sprite->Play("RightAnimation");
				}

				if (KeyCode.compare(DownKey) == 0) {
					transform->Position->y += 1;
					sprite->Play("DownAnimation");
				}

				if (KeyCode.compare(LeftKey) == 0) {
					transform->Position->x -= 1;
					sprite->Play("LeftAnimation");
				}
			}

			if (Application::ApplicationEvent.type == SDL_KEYUP) {
				std::string KeyCode = std::to_string(Application::ApplicationEvent.key.keysym.sym);
				if (KeyCode.compare(UpKey) == 0) {
					
				}

				if (KeyCode.compare(RightKey) == 0) {
					
				}

				if (KeyCode.compare(DownKey) == 0) {
					
				}

				if (KeyCode.compare(LeftKey) == 0) {
					
				}

			}
		}

		void Render() override {}
	};
}