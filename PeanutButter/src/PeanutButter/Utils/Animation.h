#pragma once
#include "PeanutButter/Core.h"

namespace PeanutButter {
	class Animation {
	public:
		pb_uint8 Index;
		pb_uint8 NumberOfFrames;
		pb_uint8 AnimationSpeed;

		Animation() {
			Index = 0;
			NumberOfFrames = 0;
			AnimationSpeed = 0;
		}

		Animation(pb_uint8 InIndex, pb_uint8 InNumberOfFrames, pb_uint8 InAnimationSpeed) {
			Index = InIndex;
			NumberOfFrames = InNumberOfFrames;
			AnimationSpeed = InAnimationSpeed;
		}
	};
}