#pragma once
#include "SFML/Graphics.hpp"
class AbstractLevel;

class MiniMap {
private:
	/// <summary>
	/// поверхность на которой происходит отрисовка объектов
	/// </summary>
	sf::RenderTexture* render_texture = nullptr;
	/// <summary>
	/// Указатель на уровень, который отображает миникарта
	/// </summary>
	AbstractLevel* level;
public:
	/// <summary>
	/// Позиция левого верхнего угла миникарты
	/// </summary>
	sf::Vector2<int> position;

	/// <summary>
	/// Ширина миникарты
	/// </summary>
	int width;

	/// <summary>
	/// Высота миникарты
	/// </summary>
	int height;

	MiniMap(AbstractLevel* level, sf::Vector2<int> position, int width, int height);

	/// <summary>
	/// обновление и перересовка миникарты на экран
	/// </summary>
	void show();

	sf::Vector2<double> getRealativePosition(sf::Vector2<double> pos);

	sf::RenderTexture* getRenderTexture();
};