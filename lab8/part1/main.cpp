#include <iostream>
#include "MyUnique.hpp"
#include "ProtectInfo.hpp"

int main() {
	std::string name = "супермегаметод";
	std::string type = "симметричный";

	auto ptr = Make_MyUnique<ProtectInfo>(name, type);

	std::cout << "тип: " << ptr->getType() << std::endl;
	ptr->print(std::cout);


	auto ptr2 = std::move(ptr);
	if (ptr.get() == nullptr) {
          std::cout << "\nptr освобожден после перемещения\n";
	}

	(*ptr2).print(std::cout);

	return 0;
}