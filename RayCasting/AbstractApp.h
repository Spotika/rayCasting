#pragma once
#include<string>

/// <summary>
/// ���������� ����������
/// </summary>
class AbstractApp {
public:
	/// <summary>
	/// ��� ����������
	/// </summary>
	std::string name;

	/// <summary>
	/// ����� ����������
	/// </summary>
	virtual void start() { throw; };
	/// <summary>
	/// �������� ���� ����������
	/// </summary>
	virtual void loop() { throw; };
	/// <summary>
	/// ��������� ����������
	/// </summary>
	virtual void stop() { throw; };
};

