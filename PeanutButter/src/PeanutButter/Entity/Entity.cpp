#include "pbpch.h"
#include "Entity.h"
#include "Component/Component.h"

namespace PeanutButter {
	Entity::Entity(EntityManager& InManager, std::string InName, ELayerType LayerType) : EManager(InManager), Name(InName), Layer(LayerType) {
		this->m_bIsActive = true;
	}

	void Entity::BeginPlay() {
		for(Component* _Component : m_Components) {
			_Component->BeginPlay();
		}
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