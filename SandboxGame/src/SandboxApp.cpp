#include <PeanutButter.h>
using namespace PeanutButter;

class BallMovementComponent : public PeanutButter::Component {
public:
	Vector2 BallVelocity;

	BallMovementComponent() : BallVelocity(100.0f, 100.0f) {}
	BallMovementComponent(const Vector2& InBallVelocity) : BallVelocity(InBallVelocity) {}

private:
	Transform* transform;

public:
	void Initialize() override {
		if (owner->HasComponentOfType<Transform>()) {
			transform = owner->GetComponentOfType<Transform>();
		}
	}

	void Update(float DeltaTime) override {
		transform->Position->x += BallVelocity.x * DeltaTime;
		transform->Position->y += BallVelocity.y * DeltaTime;

		// TODO: Remove magic numbers from here
		if ((transform->Position->x <= 0 && BallVelocity.x < 0) ||
			(transform->Position->x >= (800 - 16) && BallVelocity.x > 0)) {
			BallVelocity.x *= -1.0f;
		}
		else if ((transform->Position->y <= 0 && BallVelocity.y < 0) ||
			(transform->Position->y >= (600 - 16) && BallVelocity.y > 0)) {
			BallVelocity.y *= -1.0f;
		}
	}

	void Render() override {}
};

class PaddleMovementComponent : public PeanutButter::Component {
public:
	float Velocity;

	PaddleMovementComponent() : Velocity(0.0f) {}
	PaddleMovementComponent(float InVelocty) : Velocity(InVelocty) {}
private:
	Transform* transform;

public:
	void Initialize() override {
		if (owner->HasComponentOfType<Transform>()) {
			transform = owner->GetComponentOfType<Transform>();
		} else {
			PB_WARNING("Trying to initialize Paddle Movement Component but Entity doesn't have a Transform!");
		}
	}

	void Update(float DeltaTime) override {
		if (PeanutButter::Input::IsKeyPressed(PB_KEYCODE_W)) {
			transform->Position->y -= Velocity * DeltaTime;
		}

		if (PeanutButter::Input::IsKeyPressed(PB_KEYCODE_S)) {
			transform->Position->y += Velocity * DeltaTime;
		}
	}

	void Render() override { }
};

class Sandbox : public PeanutButter::Application {
public:
	Sandbox() {}
	Sandbox(const int& Width, const int& Height, const std::string Title) : Application(Width, Height, Title) {
		m_GameWidth = Width;
		m_GameHeight = Height;
	}

	~Sandbox() override {}

private:
	float m_GameWidth;
	float m_GameHeight;

public:
	void Start() override {
		PB_INFO("Starting Client Application");

		// Loading Pong Assets
		Application::s_AssetManager->AddTexture(std::string("pong-ball"), std::string("assets/pong/fancy-ball.png"));
		Application::s_AssetManager->AddTexture(std::string("pong-court"), std::string("assets/pong/fancy-court.png"));
		Application::s_AssetManager->AddTexture(std::string("pong-paddle-grey"), std::string("assets/pong/fancy-paddle-grey.png"));
		Application::s_AssetManager->AddTexture(std::string("pong-paddle-green"), std::string("assets/pong/fancy-paddle-green.png"));
		Application::s_AssetManager->AddTexture(std::string("pong-paddle-blue"), std::string("assets/pong/fancy-paddle-blue.png"));
		Application::s_AssetManager->AddFont(std::string("charriot-font"), std::string("assets/fonts/charriot.ttf"), 14);

		// Court Entity
		Entity& CourtBackground(Application::s_EManager->AddEntity(std::string("court-background"), ELayerType::ELT_TilemapLayer));
		CourtBackground.AddComponentOfType<Transform>(Vector2(0.0f, 0.0f), Vector2(0.0f, 0.0f), Vector2(1.0f, 1.0f));
		CourtBackground.AddComponentOfType<Sprite>(std::string("pong-court"), Vector2(800.0f, 600.0f));

		// Ball
		Entity& BallEntity(Application::s_EManager->AddEntity(std::string("ball"), ELayerType::ELT_PlayerLayer));
		// TODO: Consider pivots when positioning the ball? Would have to change the Sprite Component
		BallEntity.AddComponentOfType<Transform>(Vector2(384.0f, 284.0f), Vector2(0.0f, 0.0f), Vector2(1.0f, 1.0f));
		BallEntity.AddComponentOfType<Sprite>(std::string("pong-ball"), Vector2(32.0f, 32.0f));
		BallEntity.AddComponentOfType<BallMovementComponent>(Vector2(500.0f, 750.0f));

		// Left Paddle
		Entity& LeftPaddle(Application::s_EManager->AddEntity(std::string("left-paddle"), ELayerType::ELT_PlayerLayer));
		LeftPaddle.AddComponentOfType<Transform>(Vector2(50.0f, (300.0f - 64.0f)), Vector2(0.0f, 0.0f), Vector2(1.0f, 1.0f));
		LeftPaddle.AddComponentOfType<Sprite>(std::string("pong-paddle-blue"), Vector2(32.0f, 128.0f));
		LeftPaddle.AddComponentOfType<PaddleMovementComponent>(150.0f);
	}
};

PeanutButter::Application* PeanutButter::CreateApplication() {
	return new Sandbox(800, 600, "P(eanutButter)ONG");	
}