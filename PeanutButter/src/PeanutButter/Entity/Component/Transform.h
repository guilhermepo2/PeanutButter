#pragma once
#include "Component.h"
#include "PeanutButter/Math/Math.h"

namespace PeanutButter {
	class PB_API Transform : public Component {
	public:
		Vector2* Position;
		Vector2* Rotation;
		Vector2* Scale;

		Transform() {
			Position = new Vector2(0, 0);
			Rotation = new Vector2(0, 0);
			Scale = new Vector2(1.0, 1.0);
		}

		Transform(const Vector2& InPosition, const Vector2& InRotation, const Vector2& InScale) {
			Position = new Vector2(InPosition.x, InPosition.y);
			Rotation = new Vector2(InRotation.x, InRotation.y);
			Scale = new Vector2(InScale.x, InScale.y);
		}

		void Initialize() override {}
		void Update(float Deltatime) override {}
		void Render() override {}
	};
}