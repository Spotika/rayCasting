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
};
