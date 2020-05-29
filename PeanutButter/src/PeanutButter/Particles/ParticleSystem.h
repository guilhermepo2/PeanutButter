#pragma once
#include "PeanutButter/Core.h"
#include "PeanutButter/Math/Math.h"
#include <SDL.h>


namespace PeanutButter {
	struct ParticleProps {
		Vector2 Position;
		Vector2 Velocity;
		Vector2 VelocityVariation;
		SDL_Color Color;
		
		float SizeBegin, SizeEnd, SizeVariation;
		float LifeTime = 1.0f;
	};

	class ParticleSystem {
	public:
		ParticleSystem();
		void Update(float DeltaTime);
		void Render();
		void Emit(const ParticleProps& ParticleInfo);

	private:
		struct Particle {
			Vector2 Position;
			Vector2 Velocity;
			SDL_Color Color;
			float Rotation = 0.0f;
			float SizeBegin, SizeEnd;
			float CurrentSize;
			float LifeTime = 1.0f;
			float RemainingLifeTime = 0.0f;
			bool bIsActive;
		};

		std::vector<Particle> m_ParticlePool;
		pb_uint32 m_PoolIndex = 999;
	};
}