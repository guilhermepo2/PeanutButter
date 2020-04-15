#include "pbpch.h"
#include "Entity.h"

namespace PeanutButter {
	Entity::Entity(EntityManager& InManager, std::string InName) : EManager(InManager), Name(InName) {
		this->m_bIsActive = true;
	}

	void Entity::Update(float DeltaTime) {
		for (Component* _Component : m_Components) {
			_Component->Update(DeltaTime);
		}
	}

	void Entity::Render() {
		for (Component* _Component : m_Components) {
			_Component->Render();
		}
	}

	void Entity::Destroy() {
		// TODO: Destroy all Components?
		this->m_bIsActive = false;
	}
}