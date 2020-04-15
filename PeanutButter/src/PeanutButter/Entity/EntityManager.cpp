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

	Entity& EntityManager::AddEntity(std::string EntityName) {
		Entity* NewEntity = new Entity(*this, EntityName);
		m_AllEntities.push_back(NewEntity);
		return *NewEntity;
	}
}