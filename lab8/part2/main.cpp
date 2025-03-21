#include <iostream>
#include "MyShared.hpp"
#include "ProtectInfo.hpp"

int main() {
	auto ptr1 = Make_MyShared<ProtectInfo>("суперметод", "симметричный");
	std::cout << "Тип: " << ptr1->getType() << std::endl;

	auto ptr2 = ptr1;
	std::cout << "Счетчик после копирования: " << ptr1.use_count() << std::endl; // 2

	auto ptr3 = std::move(ptr2);
	std::cout << "Счетчик после перемещения: " << ptr1.use_count() << std::endl; // 2

	(*ptr3).print(std::cout);

	return 0;
}