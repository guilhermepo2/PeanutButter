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

		// Creating my tank entity
		Entity& TankEntity(Application::s_EManager->AddEntity("tank"));
		TankEntity.AddComponentOfType<Transform>();
		Transform* TankTransform = TankEntity.GetComponentOfType<Transform>();
		TankTransform->Position = Vector2(100, 100);
		TankTransform->Scale = Vector2(1.0, 1.0);

		TankEntity.AddComponentOfType<Sprite>("tank-image", Vector2(32, 32));
	}
};

PeanutButter::Application* PeanutButter::CreateApplication() {
	return new Sandbox();
}