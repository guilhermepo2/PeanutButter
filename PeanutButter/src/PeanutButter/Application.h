#pragma once

#include "Core.h"
#include <SDL.h>
#undef main // dumb SDL stuff
#include "PeanutButter/Log.h"
#include "PeanutButter/Entity/Component/Transform.h"
#include "PeanutButter/Particles/ParticleSystem.h"
#include "sol.hpp"

namespace PeanutButter {

	class AssetManager;
	class EntityManager;
	class Window;

	/**
	* Application Class is the main class.
	*/
	class PB_API Application {
	public:
		/** Default constructor, assumes a width, height and window title. */
		Application();
		virtual ~Application() {}
		
		/** Run function, called in the entry point. */
		void Run();

		/** Holds whether or not SDL2 was initialized */
		static bool s_bSDL2Initialized;

		/** Reference to the Renderer */
		static SDL_Renderer* s_Renderer;

		/** Reference to the abstracted window class created in the Peanut Butter Engine */
		static Window* s_Window;

		/** Asset Manager Reference */
		static AssetManager* s_AssetManager;

		/** Entity Manager Reference */
		static EntityManager* s_EManager;

		/** SDL_Rect that determines the game camera */
		static SDL_Rect s_Camera;

		/** Particle System that is used on the application */
		static ParticleSystem s_ParticleSystem;

	protected:
		/** Start function, can be overrided in the application, executed after engine initialization but before game loop starts. */
		virtual void Start();

		/** Ticks the Input module, it's the first method on the game loop. */
		void ProcessInput();

		/** Updates all the entities given a DeltaTime, it's the second method on the game loop. */
		void Update(float DeltaTime);

		/** Renders all the entities, it's the third and last method on the game loop */
		void Render();

		/** Called during update, in case m_pTransformToFollow is set to a value, will update camera position to frame the follow target in the screen. */
		void HandleCameraMovement();

		/** (DEPRECATED) Check for collisions on all entities */
		void CheckCollision();

		/** Reference to the transform that is being followed by the camera */
		Transform* m_pTransformToFollow = nullptr;

	private:
		/**
		* Initialize the engine using config.lua file.
		*/
		void Initialize();
		
		/** Whether or not the engine is still running */
		bool m_bIsRunning;

		/** Holds the value of how many ticks last frame took. */
		float m_TicksLastFrame;

	public:
		/**
		* Set transform that the camera should follow.
		* @param _Transform Transform to be followed.
		*/
		inline void SetTransformToFollow(Transform* _Transform) { m_pTransformToFollow = _Transform; }

		/**
		* Instantiate the given particle
		* @param _Props Properties of the particle to be spawned
		*/
		inline void EmitParticle(const ParticleProps& _Props) { s_ParticleSystem.Emit(_Props); }
	};

	/** Defined in the client */
	Application* CreateApplication();
}
