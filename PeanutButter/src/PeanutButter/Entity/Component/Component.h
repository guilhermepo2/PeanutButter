#pragma once
#include "PeanutButter/Entity/Entity.h"

namespace PeanutButter {

	class Entity;

	class PB_API Component {
	public:
		Component() {}
		virtual ~Component() {}
		Entity* owner;

		/** Initialize() runs when the component is created */
		virtual void Initialize() {}

		/** BeginPlay() runs after all components are initialized and before the game loop starts */
		virtual void BeginPlay() {}

		/** Update is called once per frame (am I right Unity people) */
		virtual void Update(float Deltatime) {}

		/** Render is also called once per frame */
		virtual void Render() {}
	};
}