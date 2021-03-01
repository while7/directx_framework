#pragma once
template<typename T>
class singletone
{
public:
	static T* p;
	static T* Get()
	{
		if (!p)
			p = new T;
		return p;
	}
	static void Del()
	{
		delete p;
		p = nullptr;
	}
};
template<typename T>
T* singletone<T>::p = nullptr;