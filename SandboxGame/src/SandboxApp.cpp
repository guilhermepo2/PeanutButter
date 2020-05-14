#include <PeanutButter.h>
using namespace PeanutButter;

class Sandbox : public PeanutButter::Application {
public:
	Sandbox() {}
	~Sandbox() override {}

	void Start() override {
		PB_INFO("Starting Client Application");

		// Loading Sprites into the asset mananager
		Application::s_AssetManager->AddTexture(std::string("tank-image"), std::string("assets/images/tank-big-right.png"));
		Application::s_AssetManager->AddTexture(std::string("chopper-image"), std::string("assets/images/chopper-spritesheet.png"));
		Application::s_AssetManager->AddTexture(std::string("jungle-tilemap"), std::string("assets/tilemaps/jungle.png"));
		Application::s_AssetManager->AddFont(std::string("charriot-font"), std::string("assets/fonts/charriot.ttf"), 14);

		Map* myMap = new Map(std::string("jungle-tilemap"), 2, 32);
		myMap->LoadMap(std::string("assets/tilemaps/jungle.map"), 25, 20);

		// Creating Chopper Entity
		Entity& Hero(Application::s_EManager->AddEntity(std::string("Hero Chopper"), ELayerType::ELT_PlayerLayer));
		Hero.AddComponentOfType<Transform>(Vector2(100.0, 100.0), Vector2(0, 0), Vector2(1, 1));
		Hero.AddComponentOfType<Sprite>(std::string("chopper-image"), Vector2(32.0, 32.0), 2, 90, true);
		Hero.AddComponentOfType<KeyboardControl>();
		Hero.AddComponentOfType<Collider2D>(std::string("Hero Chopper"), Vector2(0, 0), Vector2(32, 32));

		// Creating a random enemy out there...
		Entity& Tank(Application::s_EManager->AddEntity(std::string("Enemy Tank"), ELayerType::ELT_EnemyLayer));
		Tank.AddComponentOfType<Transform>(Vector2(100.0, 100.0), Vector2(0, 0), Vector2(1, 1));
		Tank.AddComponentOfType<Sprite>(std::string("tank-image"), Vector2(32.0, 32.0));
		Tank.AddComponentOfType<Collider2D>(std::string("Enemy"), Vector2(0, 0), Vector2(32, 32));

		// Adding font entity...
		Entity& Label(Application::s_EManager->AddEntity(std::string("LevelName"), ELayerType::ELT_UILayer));
		Label.AddComponentOfType<UIText>(Vector2(10.0, 10.0), std::string("First Level"), std::string("charriot-font"), PB_COLOR(255, 255, 255, 255) );

		// Setting transform for the camera to follow
		Application::SetTransformToFollow(Hero.GetComponentOfType<Transform>());
	}
};

PeanutButter::Application* PeanutButter::CreateApplication() {
	return new Sandbox();
}