#include "pbpch.h"
#include "EntityManager.h"
#include "Entity.h"

namespace PeanutButter {
	void EntityManager::Update(float DeltaTime) {
		for (Entity* _Entity : m_AllEntities) {
			_Entity->Update(DeltaTime);
		}
	}

	void EntityManager::Render() {
		for (int i = 0; i < NUMBER_OF_LAYERS; i++) {
			for (Entity* _Entity : m_AllEntities) {

			}
		}
		// TODO Render based on Layers
		for (Entity* _Entity : m_AllEntities) {
			_Entity->Render();
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
}