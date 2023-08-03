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
	/// �������� ����������, ���� ���� name �����������
	/// </summary>
	/// <param name="">��� ����������</param>
	void checkName(std::string name) {
		if (create_function_by_name.find(name) == create_function_by_name.end()) {
			throw "�� ���������� ���������� � ������ name";
		}
	}
public:
	/// <summary>
	/// ������ ��������� ����� ���������
	/// </summary>
	void startLoop();
	/// <summary>
	/// ���������� ���������� � ������� ��� �������
	/// </summary>
	/// <param name="name">��� ����������</param>
	void addAppToQueue(std::string name);
	/// <summary>
	/// ������ ���������� �� �����, �� ��������� ��������� �����������
	/// </summary>
	/// <param name="name">��� ����������</param>
	void startApp(std::string name);
	/// <summary>
	/// ���������� ������� �������� ������� ����������
	/// </summary>
	/// <param name="name">��� ����������</param>
	/// <param name="function">��������� �� �������</param>
	void addCreateFunction(std::string name, AbstractApp* (*function)());
};