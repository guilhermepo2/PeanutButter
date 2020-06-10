#include <PeanutButter.h>
#include <functional>
using namespace PeanutButter;

class BallMovementComponent : public PeanutButter::Component {
public:
	Vector2 BallVelocity;

	BallMovementComponent() : BallVelocity(100.0f, 100.0f) {}
	BallMovementComponent(const Vector2& InBallVelocity) : BallVelocity(InBallVelocity) {}

private:
	Transform* transform;
	// Creating Paddle Particle Effects
	ParticleProps MyParticle;
	ParticleSystem MyParticleSystem;

public:
	void Initialize() override {
		MyParticle.LifeTime = 0.5f;
		MyParticle.SizeBegin = 8.0f;
		MyParticle.SizeEnd = 0.0f; // TODO: Size is not updating
		MyParticle.Color = PB_COLOR_WHITE;
	}

	void BeginPlay() override {
		if (owner->HasComponentOfType<Transform>()) {
			transform = owner->GetComponentOfType<Transform>();
		}

		if (owner->HasComponentOfType<Collider2D>()) {
			// Bind Process Collision on Collider 2D
			Collider2D* ColliderComponent = owner->GetComponentOfType<Collider2D>();
			ColliderComponent->HandleCollision = std::bind(&BallMovementComponent::ProcessCollision, this, std::placeholders::_1);
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

		MyParticleSystem.Update(DeltaTime);
	}

	void Render() override {
		MyParticleSystem.Render();
	}

	void ProcessCollision(PeanutButter::Collider2D* Other) {
		// Instantiating Particles
		for (int i = 0; i < 15; i++) {
			MyParticle.Position = { transform->Position->x, transform->Position->y + PeanutButter::Random::Float() * 8.0f * 2.0f };
			MyParticle.Velocity = { PeanutButter::Random::Float() * 45.0f, PeanutButter::Random::Float() * 45.0f };
			Application::s_ParticleSystem.Emit(MyParticle);
		}

		// PB_WARNING("BALL HANDLING COLLISION!");
		if (Other->ColliderTag.compare("left-paddle") == 0 && BallVelocity.x < 0) {
			BallVelocity.x *= -1;
		}
	}
};

class PaddleMovementComponent : public PeanutButter::Component {
public:
	float Velocity;

	PaddleMovementComponent() : Velocity(0.0f) {}
	PaddleMovementComponent(float InVelocty) : Velocity(InVelocty) {}
private:
	Transform* transform;

public:
	void Initialize() override { }

	void BeginPlay() override {
		if (owner->HasComponentOfType<Transform>()) {
			transform = owner->GetComponentOfType<Transform>();
		}
		else {
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

	~Sandbox() override {}

private:
	float m_GameWidth;
	float m_GameHeight;

public:
	void Start() override {
		PB_INFO("Starting Client Application");

		// ===========================================================================
		// ===========================================================================
		// ===============   LOADS ASSETS FROM LUA ===================================
		// ===========================================================================
		// ===========================================================================
		// This shouldn't be here maybe
		sol::state lua;
		lua.open_libraries(sol::lib::base, sol::lib::os, sol::lib::math);
		lua.script_file("./assets/scripts/pong.lua");

		sol::table GameData = lua["pong"];
		sol::table GameAssets = GameData["assets"];
		
		int assetIndex = 0;
		while (true) {
			sol::optional<sol::table> existsAssetIndexNode = GameAssets[assetIndex];
			if (existsAssetIndexNode == sol::nullopt) {
				break;
			}

			sol::table asset = GameAssets[assetIndex];
			std::string assetType = asset["type"];

			if (assetType.compare("texture") == 0) {
				std::string assetId = asset["id"];
				std::string assetFile = asset["file"];
				Application::s_AssetManager->AddTexture(assetId, assetFile);
			}
			else if (assetType.compare("font") == 0) {
				std::string assetId = asset["id"];
				std::string assetFile = asset["file"];
				int fontSize = asset["fontSize"];
				Application::s_AssetManager->AddFont(assetId, assetFile, fontSize);
			}

			assetIndex++;
		}

		// ===========================================================================
		// ===========================================================================
		// ===============   LOADS ENTITIES FROM LUA =================================
		// ===========================================================================
		// ===========================================================================
		sol::table GameEntities = GameData["entities"];
		int entityIndex = 0;
		while (true) {
			sol::optional<sol::table> existsEntity = GameEntities[entityIndex];
			if (existsEntity == sol::nullopt) {
				break;
			}

			sol::table entity = GameEntities[entityIndex];
			std::string entityName = entity["name"];
			ELayerType layer = static_cast<ELayerType>(static_cast<int>(entity["layer"]));

			// add new entity
			Entity& NewEntity(Application::s_EManager->AddEntity(entityName, layer));

			sol::optional<sol::table> existComponents = entity["components"];
			if (existComponents != sol::nullopt) {
				// Checking for transform component
				sol::optional<sol::table> existstransformComponent = entity["components"]["transform"];
				if (existstransformComponent != sol::nullopt) {
					sol::table transform = entity["components"]["transform"];
					NewEntity.AddComponentOfType<Transform>(
						Vector2(transform["position"]["x"], transform["position"]["y"] ),
						Vector2(transform["rotation"]["x"], transform["rotation"]["y"]),
						Vector2(transform["scale"]["x"], transform["scale"]["y"])
					);
				}

				// checking for sprite component
				sol::optional<sol::table> existsSpriteComponent = entity["components"]["sprite"];
				if (existsSpriteComponent != sol::nullopt) {
					sol::table sprite = entity["components"]["sprite"];
					NewEntity.AddComponentOfType<Sprite>(
						sprite["texture"],
						Vector2(sprite["size"]["x"], sprite["size"]["y"])
					);
				}
			}

			entityIndex++;
		}


		// Ball
		Entity& BallEntity(Application::s_EManager->AddEntity(std::string("ball"), ELayerType::ELT_PlayerLayer));
		// TODO: Consider pivots when positioning the ball? Would have to change the Sprite Component
		BallEntity.AddComponentOfType<Transform>(Vector2(384.0f, 284.0f), Vector2(0.0f, 0.0f), Vector2(1.0f, 1.0f));
		BallEntity.AddComponentOfType<Sprite>(std::string("pong-ball"), Vector2(32.0f, 32.0f));
		BallEntity.AddComponentOfType<Collider2D>("ball", Vector2(384.0f, 284.0f), Vector2(32.0f, 32.0f));
		BallEntity.AddComponentOfType<BallMovementComponent>(Vector2(500.0f, 750.0f));

		// Left Paddle
		Entity& LeftPaddle(Application::s_EManager->AddEntity(std::string("left-paddle"), ELayerType::ELT_PlayerLayer));
		LeftPaddle.AddComponentOfType<Transform>(Vector2(50.0f, (300.0f - 64.0f)), Vector2(0.0f, 0.0f), Vector2(1.0f, 1.0f));
		LeftPaddle.AddComponentOfType<Sprite>(std::string("pong-paddle-blue"), Vector2(32.0f, 128.0f));
		LeftPaddle.AddComponentOfType<Collider2D>("left-paddle", Vector2(50.0f, (300.0f - 64.0f)), Vector2(32.0f, 128.0f));
		LeftPaddle.AddComponentOfType<PaddleMovementComponent>(750.0f);
	}
};

PeanutButter::Application* PeanutButter::CreateApplication() {
	return new Sandbox();	
}