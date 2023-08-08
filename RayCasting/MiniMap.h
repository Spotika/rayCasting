#pragma once
#include "SFML/Graphics.hpp"
#include "AbstractEntity.h"
#include "IFloatParameterControlled.h"
class AbstractLevel;

class MiniMap : public IFloatParameterControlled {
private:
	/// <summary>
	/// ������ ������������ �������� ���� �����������. ���� nullptr, �� ��������� ���������� ���� �������
	/// </summary>
	AbstractEntity* realative_target = nullptr;
	
	/// <summary>
	/// ��������� ������� ������� ��������� � ������� ������
	/// </summary>
	float view_size_fraction = 1.0f;

	/// <summary>
	/// ����������� �� ������� ���������� ��������� ��������
	/// </summary>
	sf::RenderTexture* render_texture = nullptr;
	/// <summary>
	/// ��������� �� �������, ������� ���������� ���������
	/// </summary>
	AbstractLevel* level;
public:
	/// <summary>
	/// ������� ������ �������� ���� ���������
	/// </summary>
	sf::Vector2<int> position;

	/// <summary>
	/// ������ ���������
	/// </summary>
	int width;

	/// <summary>
	/// ������ ���������
	/// </summary>
	int height;

	MiniMap(AbstractLevel* level, sf::Vector2<int> position, sf::Vector2<int> size);

	/// <summary>
	/// ���������� � ����������� ��������� �� �����
	/// </summary>
	void show();

	sf::Vector2f getRealativePosition(sf::Vector2f pos);

	sf::RenderTexture* getRenderTexture();

	void setRealativeTraget(AbstractEntity* realative_target);

	void setParameter(float value);

	void changeParameter(float diff);
};