#pragma once

#include "Core.h"
#include <SDL.h>
#undef main // dumb SDL stuff
#include "PeanutButter/Entity/Component/Transform.h"

namespace PeanutButter {

	class AssetManager;
	class EntityManager;
	class Window;

	class PB_API Application {
	public:
		Application();
		virtual ~Application() {}
		void Run();

		static bool s_bSDL2Initialized;
		static SDL_Renderer* s_Renderer;
		static Window* s_Window;
		static AssetManager* s_AssetManager;
		static EntityManager* s_EManager;
		static SDL_Rect s_Camera;

	protected:
		virtual void Start();
		void ProcessInput();
		void Update(float DeltaTime);
		void Render();
		void HandleCameraMovement();
		Transform* m_pTransformToFollow = nullptr;
		void CheckCollision();

	private:
		void Initialize();
		bool m_bIsRunning;
		float m_TicksLastFrame;

	public:
		inline void SetTransformToFollow(Transform* _Transform) { m_pTransformToFollow = _Transform; }
	};

	// Defined in the client
	Application* CreateApplication();
}
