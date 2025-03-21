#ifndef MYUNIQUE_HPP
#define MYUNIQUE_HPP

#include <utility>

template<class T>
class MyUnique {
	T *ptr = nullptr;

public:
	MyUnique(T *p);
	~MyUnique();

	MyUnique(const MyUnique&) = delete;
	MyUnique& operator=(const MyUnique&) = delete;

	T* get() const;
	T& operator*();
	T* operator->();

	MyUnique(MyUnique&& other);
	MyUnique& operator=(MyUnique&& other);
};

template <class T, class... Args>
MyUnique<T> Make_MyUnique(Args&&... args);

#include "MyUnique.tpp"

#endif