#pragma once
#include "Singleton.h"
#include "MonoFactory.h"
#include "AbstractApp.h"
#include <map>
#include <string>
#include <queue>


class AppManager : public Singleton<AppManager> {
private:
	std::map<std::string, AbstractApp* (*)()> create_function_by_name;
	std::queue<AbstractApp*> app_queue;

	/// <summary>
	/// вызывает исключение, если ключ name отсутствует
	/// </summary>
	/// <param name="">Имя приложения</param>
	void checkName(std::string name) {
		if (create_function_by_name.find(name) == create_function_by_name.end()) {
			throw "Не подключено приложение с именем name";
		}
	}
public:
	/// <summary>
	/// запуск основного цикла программы
	/// </summary>
	void startLoop();
	/// <summary>
	/// добавление приложения в очередь для запуска
	/// </summary>
	/// <param name="name">Имя приложения</param>
	void addAppToQueue(std::string name);
	/// <summary>
	/// Запуск приложения на месте, не дожидаясь окончания предыдущего
	/// </summary>
	/// <param name="name">Имя преложения</param>
	void startApp(std::string name);
	/// <summary>
	/// Добавление функции создания объекта приложения
	/// </summary>
	/// <param name="name">Имя приложения</param>
	/// <param name="function">Указатель на функцию</param>
	void addCreateFunction(std::string name, AbstractApp* (*function)());
};