#include <iostream>
#include <fstream>
#include <vector>
#include "ProtectInfo.hpp"

int main() {
	std::setlocale(LC_ALL, "ru_RU.UTF-8");
    std::ifstream inputFile("input.txt");

    int n;
    inputFile >> n;

    ProtectInfo *methods;
    methods = new ProtectInfo[n];
    std::string name, type;

    for (int i = 0; i < n; ++i) {
        inputFile >> name >> type;
        methods[i] = ProtectInfo(name, type);
    }
    inputFile.close();

    std::string searchType;
    std::cout << "Введите тип (Симметричный/Несимметричный): ";
    std::cin >> searchType;

    std::ofstream outputFile("output.txt");

    std::cout << "Методы с типом " << searchType << ":" << std::endl;
    outputFile << "Методы с типом " << searchType << ":" << std::endl;

    for (int i = 0; i < n; ++i) {
    	if (methods[i].getType() == searchType) {
        	methods[i].print(std::cout);
            methods[i].print(outputFile);
    	}
    }
    delete[] methods;

    outputFile.close();
    return 0;
}
