#pragma once
#include "SFML/Graphics.hpp"
class AbstractLevel;

class MiniMap {
private:
	/// <summary>
	/// ����������� �� ������� ���������� ��������� ��������
	/// </summary>
	sf::RenderTexture render_texture;
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
	/// ������� ���������: �����, ������
	/// </summary>
	sf::Vector2<int> dims;

	MiniMap(AbstractLevel* level);

	/// <summary>
	/// ���������� � ����������� ��������� �� �����
	/// </summary>
	void show();
};