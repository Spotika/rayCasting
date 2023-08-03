#pragma once
#include<string>

/// <summary>
/// Абстракция приложения
/// </summary>
class AbstractApp {
public:
	/// <summary>
	/// Имя приложения
	/// </summary>
	std::string name;

	/// <summary>
	/// старт приложения
	/// </summary>
	virtual void start() { throw; };
	/// <summary>
	/// основной цикл приложения
	/// </summary>
	virtual void loop() { throw; };
	/// <summary>
	/// остановка приложения
	/// </summary>
	virtual void stop() { throw; };
};

