#pragma once
#include "AbstractEntity.h"
#include "AbstractController.h"
#include "AbstractLevelPart.h"
#include<vector>


class AbstractLevel {
public:

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

	int width{};

	int height{};


	/// <summary>
	/// 
	/// </summary>
	/// <returns>Возвращает ширину уровня</returns>
	virtual int getWidth() { throw; };

	/// <summary>
	/// 
	/// </summary>
	/// <returns>Возвращает высоту уровня</returns>
	virtual int getHeight() { throw; }


	/// <summary>
	/// обновление всех сущностей, контроллеров и самого уровня
	/// </summary>
	virtual void update() {
		// обновление контроллеров
		for (AbstractController* controller : controllers) {
			controller->update();
		}

		// обновление сущностей
		for (AbstractEntity* entity : entities) {
			entity->update();
		}
	}

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

