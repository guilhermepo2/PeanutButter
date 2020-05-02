#pragma once
#include <SDL.h>

namespace PeanutButter {
	class Collision {
	public:
		static bool CheckRectangleCollision(const SDL_Rect& RectangleA, const SDL_Rect& RectangleB);
	};
}
