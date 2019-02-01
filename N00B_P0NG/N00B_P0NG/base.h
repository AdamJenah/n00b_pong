#pragma once

template <class T>
class base
{
public:
	static T* Instance();
};

template <class T>
T* base<T>::Instance()
{
	static T* inst = new T();
	return inst;
}
