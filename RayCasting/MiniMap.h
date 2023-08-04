#pragma once
#include "SFML/Graphics.hpp"
class AbstractLevel;

class MiniMap {
private:
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

	MiniMap(AbstractLevel* level, sf::Vector2<int> position, int width, int height);

	/// <summary>
	/// ���������� � ����������� ��������� �� �����
	/// </summary>
	void show();

	sf::Vector2<double> getRealativePosition(sf::Vector2<double> pos);

	sf::RenderTexture* getRenderTexture();
};