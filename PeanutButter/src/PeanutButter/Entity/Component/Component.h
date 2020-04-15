#pragma once

class Entity;

namespace PeanutButter {
	class Component {
	public:
		Component() {}
		virtual ~Component() {}
		Entity* owner;

		virtual void Initialize() = 0;
		virtual void Update(float Deltatime) = 0;
		virtual void Render() = 0;
	};
}