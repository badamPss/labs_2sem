#include "Vector.hpp"
#include <fstream>

int main() {
    std::setlocale(LC_ALL, "ru_RU.UTF-8");
    std::ifstream inputFile("input.txt");

    Vector v1, v2;
    inputFile >> v1;
    inputFile >> v2;
    inputFile.close();

    Vector copyVector = v1;
    Vector moveVector = std::move(v2);

    Vector assignedCopy;
    assignedCopy = copyVector;

    Vector assignedMove;
    assignedMove = std::move(moveVector);

    Vector sumVector = v1 + assignedCopy;

    std::ofstream outputFile("output.txt");
    outputFile << "Исходный вектор v1: " << v1 << std::endl;
    outputFile << "Копия v1: " << copyVector << std::endl;
    outputFile << "Сумма v1 + копии: " << sumVector << std::endl;

    outputFile.close();
    return 0;
}
