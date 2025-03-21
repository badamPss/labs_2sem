#ifndef MYSHARED_HPP
#define MYSHARED_HPP

#include <utility>

template <class T>
class MyShared {
	struct ControlBlock {
		T* ptr = nullptr;
		unsigned count = 1;
	};

	ControlBlock* ctrl = nullptr;

	void release();

public:
	MyShared(T* p = nullptr);
	MyShared(const MyShared& other);
	MyShared(MyShared&& other);
	~MyShared();

	MyShared& operator=(const MyShared& other);
	MyShared& operator=(MyShared&& other);

	T* get() const;
	T& operator*() const;
	T* operator->() const;

	unsigned use_count() const;
};

template <class T, class... Args>
MyShared<T> Make_MyShared(Args&&... args);

#include "MyShared.tpp"

#endif