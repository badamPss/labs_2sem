#ifndef MYSHARED_TPP
#define MYSHARED_TPP

#include "MyShared.hpp"

template <class T>
void MyShared<T>::release() {
	if (ctrl) {
		ctrl->count--;
		if (ctrl->count == 0) {
			delete ctrl->ptr;
			delete ctrl;
		}
	}
}

template <class T>
MyShared<T>::MyShared(T* p) : ctrl(new ControlBlock{p, 1}) {}

template <class T>
MyShared<T>::MyShared(const MyShared& other) : ctrl(other.ctrl) {
	if (ctrl) ctrl->count++;
}

template <class T>
MyShared<T>::MyShared(MyShared&& other) : ctrl(other.ctrl) {
	other.ctrl = nullptr;
}

template <class T>
MyShared<T>::~MyShared() {
	release();
}

template <class T>
MyShared<T>& MyShared<T>::operator=(const MyShared& other) {
	if (this != &other) {
		release();
		ctrl = other.ctrl;
		if (ctrl) ctrl->count++;
	}
	return *this;
}

template <class T>
MyShared<T>& MyShared<T>::operator=(MyShared&& other) {
	if (this != &other) {
		release();
		ctrl = other.ctrl;
		other.ctrl = nullptr;
	}
	return *this;
}

template <class T>
T* MyShared<T>::get() const {
	if (ctrl) {
		return ctrl->ptr;
	}
	return nullptr;
}

template <class T>
T& MyShared<T>::operator*() const {
	return *get();
}

template <class T>
T* MyShared<T>::operator->() const {
	return get();
}

template <class T>
unsigned MyShared<T>::use_count() const {
	if (ctrl) {
    	return ctrl->count;
    }
    return 0;
}

template <class T, class... Args>
MyShared<T> Make_MyShared(Args&&... args) {
	return MyShared<T>(new T(args...));
}

#endif