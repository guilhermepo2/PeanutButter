#pragma once
#include "PeanutButter/Core.h"
#include <vector>
#include <string>

namespace PeanutButter {

	class Entity;

	class PB_API EntityManager {
	public:
		void Update(float DeltaTime);
		void Render();
		void Clear();

	private:
		std::vector<Entity*> m_AllEntities;

	public:
		Entity& AddEntity(std::string EntityName);

		// TODO Get All Entities by Layer
		inline std::vector<Entity*> GetAllEntities() const { return m_AllEntities; }
		inline pb_uint16 GetEntitiesCount() const { return m_AllEntities.size(); }
		inline bool HasEntities() const { return m_AllEntities.size() != 0; }
	};
}