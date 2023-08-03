#pragma once
#include "Singleton.h"
#include <vector>
#include "SFML/Graphics.hpp"


class EventHandler : public Singleton<EventHandler> {
private:
	std::vector<sf::Event> *event_list = nullptr;
	/// <summary>
	/// Отслеживание глобальных событий
	/// </summary>
	/// <param name="event">объект - событие</param>
	void handleGlobalEvent(sf::Event event);
public:
	/// <summary>
	/// Инициализация системы событий
	/// </summary>
	void init();
	/// <summary>
	/// обновление событий, вызывается в цикле приложения
	/// </summary>
	void update();
	/// <summary> 
	/// </summary>
	/// <returns>Возвращает указатель на вектор событий</returns>
	std::vector<sf::Event>* getEvents();
};
