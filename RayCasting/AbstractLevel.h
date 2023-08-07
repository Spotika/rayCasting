#pragma once
#include "AbstractEntity.h"
#include "AbstractController.h"
#include "AbstractLevelPart.h"
#include<vector>


class AbstractLevel {
public:

	/// <summary>
	/// ����� ������
	/// </summary>
	std::vector<AbstractLevelPart*> level_parts;
	/// <summary>
	/// ������ ��������� ������
	/// </summary>
	std::vector<AbstractEntity*> entities;
	/// <summary>
	/// ������ ������������
	/// </summary>
	std::vector<AbstractController*> controllers;

	int width{};

	int height{};


	/// <summary>
	/// 
	/// </summary>
	/// <returns>���������� ������ ������</returns>
	virtual int getWidth() { throw; };

	/// <summary>
	/// 
	/// </summary>
	/// <returns>���������� ������ ������</returns>
	virtual int getHeight() { throw; }


	/// <summary>
	/// ���������� ���� ���������, ������������ � ������ ������
	/// </summary>
	virtual void update() {
		// ���������� ������������
		for (AbstractController* controller : controllers) {
			controller->update();
		}

		// ���������� ���������
		for (AbstractEntity* entity : entities) {
			entity->update();
		}
	}

	/// <summary>
	/// ���������� ��������� � �������
	/// </summary>
	/// <param name="entity">��������� �� ��������</param>
	void addEntity(AbstractEntity* entity) {
		entities.push_back(entity);
	}

	/// <summary>
	/// ���������� � ������ �����������
	/// </summary>
	/// <param name="controller">��������� �� ����������</param>
	void addController(AbstractController* controller) {
		controllers.push_back(controller);
	}
};

