#pragma once
#include "SFML/Graphics.hpp"
class AbstractLevel;

class MiniMap {
private:
	/// <summary>
	/// поверхность на которой происходит отрисовка объектов
	/// </summary>
	sf::RenderTexture render_texture;
	/// <summary>
	/// ”казатель на уровень, который отображает миникарта
	/// </summary>
	AbstractLevel* level;
public:
	/// <summary>
	/// ѕозици€ левого верхнего угла миникарты
	/// </summary>
	sf::Vector2<int> position;
	/// <summary>
	/// размеры миникарты: шириа, высота
	/// </summary>
	sf::Vector2<int> dims;

	MiniMap(AbstractLevel* level);

	/// <summary>
	/// обновление и перересовка миникарты на экран
	/// </summary>
	void show();
};