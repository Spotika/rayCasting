#pragma once
#include "Singleton.h"
#include "SFML/Graphics.hpp"

class Screen : public Singleton<Screen> {
private:
	sf::RenderWindow* render_window = nullptr;
public:
	/// <summary>
	/// �������������� ����� �������
	/// </summary>
	void init();
	/// <summary>
	/// </summary>
	/// <returns>���������� ��������� �� ������ ����</returns>
	sf::RenderWindow* getRenderWindow();
};
