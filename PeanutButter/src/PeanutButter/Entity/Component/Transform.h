#pragma once
#include "Component.h"
#include "PeanutButter/Math/Math.h"

namespace PeanutButter {
	class Transform : public Component {
	public:
		Vector2 Position;
		Vector2 Rotation;
		Vector2 Scale;

		Transform() : Position(Vector2::Zero), Rotation(Vector2::Zero), Scale(Vector2::One) {
			PB_CORE_INFO("Transform() constructor");
		}

		Transform(Vector2 InPosition, Vector2 InRotation, Vector2 InScale) : Position(InPosition), Rotation(InRotation), Scale(InScale) {
			PB_CORE_INFO("Transform(Vector2, Vector2, Vector2) constructor");
		}

		void Initialize() override {}
		void Update(float Deltatime) override {}
		void Render() override {}
	};
}