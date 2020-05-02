#pragma once
#include "EntityManager.h"
#include <map>
#include <typeinfo>

namespace PeanutButter {
	class Component;

	class PB_API Entity {
	public:
		std::string Name;
		ELayerType Layer;
		Entity(EntityManager& InManager, std::string InName, ELayerType LayerType);

	protected:
		EntityManager& EManager;
		bool m_bIsActive;
		std::vector<Component*> m_Components;
		std::map<const std::type_info*, Component*> m_ComponentTypeMap;

	public:
		void Update(float DeltaTime);
		void Render();
		void Destroy();

		inline bool IsActive() const { return m_bIsActive; }

		template<typename T, typename... TArgs>
		T& AddComponentOfType(TArgs&&... Args) {
			T* NewComponent(new T(std::forward<TArgs>(Args)...));
			NewComponent->owner = this;
			m_Components.push_back(NewComponent);
			m_ComponentTypeMap[&typeid(*NewComponent)] = NewComponent;
			NewComponent->Initialize();
			return *NewComponent;
		}

		template<typename T>
		T* GetComponentOfType() {
			return static_cast<T*>(m_ComponentTypeMap[&typeid(T)]);
		}

		template<typename T>
		bool HasComponentOfType() const {
			return m_ComponentTypeMap.count(&typeid(T));
		}
	};

}
