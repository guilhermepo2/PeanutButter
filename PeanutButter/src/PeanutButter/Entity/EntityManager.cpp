#include "pbpch.h"
#include "PeanutButter/Log.h"
#include "EntityManager.h"
#include "Entity.h"
#include "PeanutButter/Physics/Collision.h"
#include "PeanutButter/Entity/Component/Collider2D.h"

namespace PeanutButter {
	void EntityManager::BeginPlay() {
		for (Entity* _Entity : m_AllEntities) {
			_Entity->BeginPlay();
		}
	}

	void EntityManager::Update(float DeltaTime) {
		for (Entity* _Entity : m_AllEntities) {
			_Entity->Update(DeltaTime);
		}
	}

	void EntityManager::Render() {
		for (int i = 0; i < NUMBER_OF_LAYERS; i++) {
			std::vector<Entity*> ThisLayer = GetEntitiesByLayer(static_cast<ELayerType>(i));

			for (Entity* _Entity : ThisLayer) {
				_Entity->Render();
			}
		}
	}

	void EntityManager::Clear() {
		for (Entity* _Entity : m_AllEntities) {
			_Entity->Destroy();
		}
	}

	Entity& EntityManager::AddEntity(std::string EntityName, ELayerType LayerType) {
		Entity* NewEntity = new Entity(*this, EntityName, LayerType);
		m_AllEntities.push_back(NewEntity);
		return *NewEntity;
	}

	std::vector<Entity*> EntityManager::GetEntitiesByLayer(ELayerType Layer) const {
		std::vector<Entity*> Entities;

		for (Entity* _Entity : m_AllEntities) {
			if (_Entity->Layer == Layer) {
				Entities.emplace_back(_Entity);
			}
		}

		return Entities;
	}

	// TODO: This is bad - it checks all entities for one collision
	// This ideally should be done on the Collider Component, each collider should check if they collided with something and take from there...
	ECollisionType EntityManager::CheckCollisionOnAllEntities() const {
		for (Entity* ThisEntity : m_AllEntities) {
			if (ThisEntity->HasComponentOfType<Collider2D>()) {
				Collider2D* ThisCollider = ThisEntity->GetComponentOfType<Collider2D>();

				for (Entity* OtherEntity : m_AllEntities) {
					if (
						OtherEntity->Name.compare(ThisEntity->Name) != 0 &&
						OtherEntity->HasComponentOfType<Collider2D>()
						) {
						Collider2D* OtherCollider = OtherEntity->GetComponentOfType<Collider2D>();

						if (Collision::CheckRectangleCollision(ThisCollider->Collider, OtherCollider->Collider)) {
							// PB_CORE_INFO("Collision between {0} and {1}", ThisEntity->Name, OtherEntity->Name);
							return ECL_Collision;
						}
					}
				}
			}
		}

		return ECL_NoCollision;
	}
}