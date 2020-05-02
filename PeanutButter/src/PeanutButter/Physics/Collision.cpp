#include "pbpch.h"
#include "Collision.h"

namespace PeanutButter {

	/**
	* Check collision between two rectangles using the AABB method
	* @param RectangleA - Rectangle to check collision with.
	* @param RectangleB - Rectangle to check collision with.
	* @return Whether both rectangles collide or not.
	*/
	bool Collision::CheckRectangleCollision(const SDL_Rect& RectangleA, const SDL_Rect& RectangleB) {
		return(
			RectangleA.x + RectangleA.w >= RectangleB.x &&
			RectangleB.x + RectangleB.w >= RectangleA.x &&
			RectangleA.y + RectangleA.h >= RectangleB.y &&
			RectangleB.y + RectangleB.h >= RectangleA.y
			);
	}
}