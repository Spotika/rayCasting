#pragma once
#include "AbstractEntity.h"
#include "AbstractLevelPart.h"
#include<vector>


class AbstractLevel {
private:
	/// <summary>
	/// ����� ������
	/// </summary>
	std::vector<AbstractLevelPart*> level_parts;
	/// <summary>
	/// ������ ��������� ������
	/// </summary>
	std::vector<AbstractEntity*> entities;
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
};

