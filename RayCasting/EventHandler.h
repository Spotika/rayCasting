#pragma once
#include "Singleton.h"
#include <vector>
#include "SFML/Graphics.hpp"


class EventHandler : public Singleton<EventHandler> {
private:
	std::vector<sf::Event> *event_list = nullptr;
	/// <summary>
	/// ������������ ���������� �������
	/// </summary>
	/// <param name="event">������ - �������</param>
	void handleGlobalEvent(sf::Event event);

	/// <summary>
	/// ����� � �������� ����������
	/// </summary>
	float time_elapsed = 0;

	/// <summary>
	/// ���������� ����
	/// </summary>
	sf::Clock* clock = nullptr;
public:
	/// <summary>
	/// ������������� ������� �������
	/// </summary>
	void init();
	/// <summary>
	/// ���������� �������, ���������� � ����� ����������
	/// </summary>
	void update();
	/// <summary> 
	/// </summary>
	/// <returns>���������� ��������� �� ������ �������</returns>
	std::vector<sf::Event>* getEvents();

	/// <summary>
	/// 
	/// </summary>
	/// <returns>��������� �� ������ clock</returns>
	sf::Clock* getClock();

	/// <summary>
	/// ���������� ����� � �������� � �������� ����������
	/// </summary>
	float getTimeElapsed();
};
