#pragma once
#include "SFML/Graphics.hpp"
#include "AbstractEntity.h"
#include "IFloatParameterControlled.h"
class AbstractLevel;

class MiniMap : public IFloatParameterControlled {
private:
	/// <summary>
	/// объект относительно которого идет отображение. ≈сли nullptr, то миникарта отображает весь уровень
	/// </summary>
	AbstractEntity* realative_target = nullptr;
	
	/// <summary>
	/// отношение размера области видимости к размеру уровн€
	/// </summary>
	float view_size_fraction = 1.0f;

	/// <summary>
	/// поверхность на которой происходит отрисовка объектов
	/// </summary>
	sf::RenderTexture* render_texture = nullptr;
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
	/// Ўирина миникарты
	/// </summary>
	int width;

	/// <summary>
	/// ¬ысота миникарты
	/// </summary>
	int height;

	MiniMap(AbstractLevel* level, sf::Vector2<int> position, sf::Vector2<int> size);

	/// <summary>
	/// обновление и перересовка миникарты на экран
	/// </summary>
	void show();

	sf::Vector2f getRealativePosition(sf::Vector2f pos);

	sf::RenderTexture* getRenderTexture();

	void setRealativeTraget(AbstractEntity* realative_target);

	void setParameter(float value);

	void changeParameter(float diff);
};