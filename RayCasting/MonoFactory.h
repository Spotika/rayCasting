#pragma once

template<class Gen, class Type> class MonoFactory {
private:
	
public:
	/// <summary>
	/// Создает и возвращает функцию, создающую объект типа Type и приводит к более широкому типу Gen
	/// </summary>
	/// <returns>Возвращает указатель на созданную функцию</returns>
	Gen* (*getCreateFunction())() {
		Gen* (*function)() = []() {
			return (Gen*)new Type();
		};
		return function;
	};
};