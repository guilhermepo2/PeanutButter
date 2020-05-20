#pragma once
#include "PeanutButter/Core.h"
#include <vector>
#include <string>

namespace PeanutButter {

	class Entity;

	class PB_API EntityManager {
	public:
		void BeginPlay();
		void Update(float DeltaTime);
		void Render();
		void Clear();

	private:
		std::vector<Entity*> m_AllEntities;

	public:
		Entity& AddEntity(std::string EntityName, ELayerType LayerType);
		inline std::vector<Entity*> GetAllEntities() const { return m_AllEntities; }
		inline pb_uint16 GetEntitiesCount() const { return m_AllEntities.size(); }
		std::vector<Entity*> GetEntitiesByLayer(ELayerType Layer) const;
		inline bool HasEntities() const { return m_AllEntities.size() != 0; }

		// TODO: Is this the better place for this?
		ECollisionType CheckCollisionOnAllEntities() const;
	};
}