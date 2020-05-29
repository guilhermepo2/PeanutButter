#include "pbpch.h"
#include "ParticleSystem.h"
#include "PeanutButter/Application.h"
#include "PeanutButter/Utils/Random.h"

namespace PeanutButter {
	ParticleSystem::ParticleSystem() {
		m_ParticlePool.resize(1000);
	}

	void ParticleSystem::Update(float DeltaTime) {
		for (auto& Particle : m_ParticlePool) {
			if (!Particle.bIsActive) {
				continue;
			}

			if (Particle.RemainingLifeTime <= 0.0f) {
				Particle.bIsActive = false;
				continue;
			}

			Particle.RemainingLifeTime -= DeltaTime;
			Particle.Position += Particle.Velocity * DeltaTime;
			
			// TODO: Make the rotation here a parameter...
			Particle.Rotation += 1.0f * DeltaTime;

			// TODO: Scale Size
			Particle.CurrentSize = Particle.SizeEnd + ( (Particle.RemainingLifeTime / Particle.LifeTime) * (Particle.SizeEnd - Particle.SizeBegin));
		}
	}

	void ParticleSystem::Render() {
		for (auto& Particle : m_ParticlePool) {
			if (!Particle.bIsActive) {
				continue;
			}

			SDL_Color ParticleColor = Particle.Color;
			SDL_SetRenderDrawColor(Application::s_Renderer, ParticleColor.r, ParticleColor.g, ParticleColor.b, ParticleColor.a);

			SDL_Rect ParticleRect{
				static_cast<int>(Particle.Position.x),
				static_cast<int>(Particle.Position.y),
				Particle.CurrentSize,
				Particle.CurrentSize
			};

			// TODO: Rotate

			SDL_RenderFillRect(Application::s_Renderer, &ParticleRect);
		}
	}

	void ParticleSystem::Emit(const ParticleProps& ParticleInfo) {
		auto& _Particle = m_ParticlePool[m_PoolIndex];
		_Particle.bIsActive = true;
		_Particle.Position = ParticleInfo.Position;
		_Particle.Rotation = Random::Float();

		// Velocity
		_Particle.Velocity = ParticleInfo.Velocity;

		_Particle.Color = ParticleInfo.Color;

		_Particle.LifeTime = ParticleInfo.LifeTime;
		_Particle.RemainingLifeTime = ParticleInfo.LifeTime;
		_Particle.SizeBegin = ParticleInfo.SizeBegin; // TODO: Add Size Variation here
		_Particle.SizeEnd = ParticleInfo.SizeEnd;
		_Particle.CurrentSize = ParticleInfo.SizeBegin;

		m_PoolIndex = --m_PoolIndex % m_ParticlePool.size();
	}
}