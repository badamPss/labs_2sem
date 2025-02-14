#include <iostream>
#include <fstream>
#include "Deposit.h"
#include <vector>
#include <deque>

int main() {
	std::setlocale(LC_ALL, "ru_RU.UTF-8");
	std::ifstream inputFile("input.txt");

	std::vector<Deposit> deposits;
	Deposit deposit;
	while (inputFile >> deposit) {
		deposits.push_back(deposit);
	}
	inputFile.close();

	std::deque<Deposit> deposits_copy(deposits.size());
	std::copy(deposits.begin(), deposits.end(), deposits_copy.begin());

	std::ofstream outputFile("output.txt");
	outputFile << "Оригинальныйй без сортировки:" << std::endl;
	for (const auto& deposit : deposits) {
		outputFile << deposit;
	}

	outputFile << "\nСкопированный без сортировки" << std::endl;
	for (const auto& deposit_copy : deposits_copy) {
		outputFile << deposit_copy;
	}

	outputFile << "\nОригинальный после сортировки:" << std::endl;
	std::sort(deposits.begin(), deposits.end());
	for (const auto& deposit : deposits) {
		outputFile << deposit;
	}

	outputFile.close();
	return 0;
}