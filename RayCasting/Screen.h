#pragma once
#include "Singleton.h"
#include "SFML/Graphics.hpp"

class Screen : public Singleton<Screen> {
private:
	sf::RenderWindow* render_window = nullptr;
public:
	/// <summary>
	/// Инициализирует видео систему
	/// </summary>
	void init();
	/// <summary>
	/// </summary>
	/// <returns>Возвращает указатель на объект окна</returns>
	sf::RenderWindow* getRenderWindow();
};
