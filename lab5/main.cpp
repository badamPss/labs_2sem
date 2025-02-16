#include "Deposit.h"
#include <set>
#include <unordered_set>
#include <fstream>

int main() {
	std::setlocale(LC_ALL, "ru_RU.UTF-8");
	std::ifstream inputFile("input.txt");

	std::set<Deposit> deposits_set;
	std::unordered_set<Deposit, DepositHash> deposits_unordered_set;

	Deposit deposit;
	while (inputFile >> deposit) {
		deposits_set.insert(deposit);
		deposits_unordered_set.insert(deposit);
	}
	inputFile.close();

	std::ofstream outputFile("output.txt");
	outputFile << "Set:" << std::endl;
	for (const auto& deposit : deposits_set) {
		outputFile << deposit;
	}

	outputFile << "\nUnordered set" << std::endl;
	for (const auto& deposit : deposits_unordered_set) {
		outputFile << deposit;
	}

	outputFile.close();
	return 0;
}