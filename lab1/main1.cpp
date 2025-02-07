#include <iostream>
#include <fstream>
#include <vector>
#include "ProtectInfo.hpp"

int main() {
    std::setlocale(LC_ALL, "ru_RU.UTF-8");
    std::ifstream inputFile("input.txt");

    int n;
    inputFile >> n;

    std::vector<ProtectInfo> methods;
    std::string name, type;

    for (int i = 0; i < n; ++i) {
        inputFile >> name >> type;
        methods.emplace_back(name, type);
    }
    inputFile.close();

    std::string searchType;
    std::cout << "Введите тип (Симметричный/Несимметричный): ";
    std::cin >> searchType;

    std::ofstream outputFile("output.txt");

    std::cout << "Методы с типом " << searchType << ":" << std::endl;
    outputFile << "Методы с типом " << searchType << ":" << std::endl;

    for (const auto& method : methods) {
        if (method.getType() == searchType) {
            method.print(std::cout);
            method.print(outputFile);
        }
    }

    outputFile.close();
    return 0;
}
