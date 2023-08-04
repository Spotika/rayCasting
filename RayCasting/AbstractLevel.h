#pragma once
#include "AbstractEntity.h"
#include "AbstractController.h"
#include "AbstractLevelPart.h"
#include<vector>


class AbstractLevel {
protected:
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
public:
	/// <summary>
	/// ���������� ���� ��������� � ������ ������
	/// </summary>
	virtual void update() { throw; }

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

