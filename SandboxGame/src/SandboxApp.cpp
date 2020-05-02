#include <PeanutButter.h>
using namespace PeanutButter;

class Sandbox : public PeanutButter::Application {
public:
	Sandbox() {}
	~Sandbox() override {}

	void Start() override {
		PB_INFO("Starting Client Application");

		// Loading Sprites into the asset mananager
		Application::s_AssetManager->AddTexture("tank-image", "assets/images/tank-big-right.png");
		Application::s_AssetManager->AddTexture("chopper-image", "assets/images/chopper-spritesheet.png");
		Application::s_AssetManager->AddTexture("hero-character", "assets/chara_hero.png");
		Application::s_AssetManager->AddTexture("jungle-tilemap", "assets/tilemaps/jungle.png");

		Map* myMap = new Map("jungle-tilemap", 2, 32);
		myMap->LoadMap("assets/tilemaps/jungle.map", 25, 20);

		// Creating Chopper Entity
		Entity& Hero(Application::s_EManager->AddEntity("Hero Chopper", ELayerType::ELT_PlayerLayer));
		Hero.AddComponentOfType<Transform>(Vector2(100.0, 100.0), Vector2(0, 0), Vector2(1, 1));
		Hero.AddComponentOfType<Sprite>("chopper-image", Vector2(32.0, 32.0), 2, 90, true);
		Hero.AddComponentOfType<KeyboardControl>("up", "right", "down", "left");
		Hero.AddComponentOfType<Collider2D>("Hero Chopper", Vector2(0, 0), Vector2(32, 32));

		// Creating a random enemy out there...
		Entity& Tank(Application::s_EManager->AddEntity("Enemy Tank", ELayerType::ELT_EnemyLayer));
		Tank.AddComponentOfType<Transform>(Vector2(100.0, 100.0), Vector2(0, 0), Vector2(1, 1));
		Tank.AddComponentOfType<Sprite>("tank-image", Vector2(32.0, 32.0));
		Tank.AddComponentOfType<Collider2D>("Enemy", Vector2(0, 0), Vector2(32, 32));

		Application::SetTransformToFollow(Hero.GetComponentOfType<Transform>());
	}
};

PeanutButter::Application* PeanutButter::CreateApplication() {
	return new Sandbox();
}