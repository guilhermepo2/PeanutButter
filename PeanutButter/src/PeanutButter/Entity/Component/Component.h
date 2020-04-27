#pragma once
#include "PeanutButter/Entity/Entity.h"

namespace PeanutButter {

	class Entity;

	class PB_API Component {
	public:
		Component() {}
		virtual ~Component() {}
		Entity* owner;

		virtual void Initialize() {}
		virtual void Update(float Deltatime) {}
		virtual void Render() {}
	};
}