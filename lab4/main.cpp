#include <iostream>
#include <fstream>
#include "Deposit.h"
#include <vector>

int main() {
	std::setlocale(LC_ALL, "ru_RU.UTF-8");
	std::ifstream inputFile("input.txt");

	std::vector<Deposit> deposits;
	Deposit deposit;
	while (inputFile >> deposit) {
		deposits.push_back(deposit);
	}
	inputFile.close();

	std::ofstream outputFile("output.txt");
	outputFile << "До сортировки:" << std::endl;
	for (const auto& deposit : deposits) {
		outputFile << deposit;
	}
	outputFile << "\nПосле сортировки:" << std::endl;
	std::sort(deposits.begin(), deposits.end());
	for (const auto& deposit : deposits) {
		outputFile << deposit;
	}
	outputFile.close();
	return 0;
}