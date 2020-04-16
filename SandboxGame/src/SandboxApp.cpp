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
		Application::s_AssetManager->AddTexture("hero-character", "assets/chara_hero.png");

		// Creating Hero Entity
		Entity& Hero(Application::s_EManager->AddEntity("Hero"));
		Hero.AddComponentOfType<Transform>(Vector2(100.0, 100.0), Vector2(0, 0), Vector2(1, 1));
		Hero.AddComponentOfType<Sprite>("hero-character", Vector2(64.0, 64.0));
	}
};

PeanutButter::Application* PeanutButter::CreateApplication() {
	return new Sandbox();
}