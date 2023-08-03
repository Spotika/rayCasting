#pragma once


template<class T> class Singleton {
protected:
	/// <summary>
	/// ������ �� ������������ ������
	/// </summary>
	static inline T* instance = nullptr;
	Singleton() {}
public:
	Singleton(Singleton const&) = delete;
	void operator = (Singleton const&) = delete;

	/// <summary>
	/// 
	/// </summary>
	/// <returns>������ �� ������������ ������ ������</returns>
	static T* getInstance() {
		if (instance == nullptr) {
			instance = new T();
		}
		return instance;
	}
};

