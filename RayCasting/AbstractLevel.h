#pragma once
#include "AbstractEntity.h"
#include "AbstractLevelPart.h"
#include<vector>


class AbstractLevel {
private:
	/// <summary>
	/// Части уровня
	/// </summary>
	std::vector<AbstractLevelPart*> level_parts;
	/// <summary>
	/// Список сущностей уровня
	/// </summary>
	std::vector<AbstractEntity*> entities;
public:
	/// <summary>
	/// обновление всех сущностей и самого уровня
	/// </summary>
	virtual void update() { throw; }

	/// <summary>
	/// добавление сущностей в уровень
	/// </summary>
	/// <param name="entity">указатель на сущность</param>
	void addEntity(AbstractEntity* entity) {
		entities.push_back(entity);
	}
};

