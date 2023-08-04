#pragma once
#include "AbstractEntity.h"
#include "AbstractController.h"
#include "AbstractLevelPart.h"
#include<vector>


class AbstractLevel {
protected:
	/// <summary>
	/// Части уровня
	/// </summary>
	std::vector<AbstractLevelPart*> level_parts;
	/// <summary>
	/// Список сущностей уровня
	/// </summary>
	std::vector<AbstractEntity*> entities;
	/// <summary>
	/// Список контроллеров
	/// </summary>
	std::vector<AbstractController*> controllers;
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

	/// <summary>
	/// Добавление в список контроллера
	/// </summary>
	/// <param name="controller">Указатель на контроллер</param>
	void addController(AbstractController* controller) {
		controllers.push_back(controller);
	}
};

