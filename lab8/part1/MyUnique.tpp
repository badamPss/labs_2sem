#ifndef MYUNIQUE_TPP
#define MYUNIQUE_TPP

#include "MyUnique.hpp"

template <class T>
MyUnique<T>::MyUnique(T* ptr) {
	this->ptr = ptr;
}

template <class T>
MyUnique<T>::~MyUnique() {
	delete ptr;
}

template <class T>
T* MyUnique<T>::get() const {
	return ptr;
}

template <class T>
T& MyUnique<T>::operator*() {
	return *ptr;
}

template <class T>
T* MyUnique<T>::operator->() {
	return ptr;
}

template <class T>
MyUnique<T>::MyUnique(MyUnique&& other) : ptr(other.ptr) {
	other.ptr = nullptr;
}

template <class T>
MyUnique<T>& MyUnique<T>::operator=(MyUnique&& other) {
	if (this != &other) {
		delete ptr;
		ptr = other.ptr;
		other.ptr = nullptr;
	}
	return *this;
}

template <class T, class... Args>
MyUnique<T> Make_MyUnique(Args&&... args) {
	return MyUnique<T>(new T(args...));
}

#endif