#pragma once

template<class Gen, class Type> class MonoFactory {
private:
	
public:
	/// <summary>
	/// ������� � ���������� �������, ��������� ������ ���� Type � �������� � ����� �������� ���� Gen
	/// </summary>
	/// <returns>���������� ��������� �� ��������� �������</returns>
	Gen* (*getCreateFunction())() {
		Gen* (*function)() = []() {
			return (Gen*)new Type();
		};
		return function;
	};
};