#include "ArithmeticProgression.h"

InvalidProgressionException::InvalidProgressionException(const std::string& message, const ArithmeticProgression* prog)
	: std::invalid_argument(message), invalidProgression(prog) {}

void InvalidProgressionException::printError() const {
	std::cerr << what() << std::endl;
	if (invalidProgression) {
		std::cerr << "Ожидалось: первый элемент = " << invalidProgression->first
				  << ", разность = " << invalidProgression->difference << std::endl;
		std::cerr << "Полученный массив: ";
		for (int i = 0; i < invalidProgression->size; ++i) {
			std::cerr << invalidProgression->sequence[i] << " ";
		}
		std::cerr << std::endl;
	}
}

ArithmeticProgression::ArithmeticProgression(double first, double difference, double* arr, int size) : first(first), difference(difference), sequence(arr), size(size) {
	if (!isValidProgression()) {
		throw InvalidProgressionException("Ошибка: массив не является арифметической прогрессией!", this);
	}
}

ArithmeticProgression::~ArithmeticProgression() {
	delete[] sequence;
}

bool ArithmeticProgression::isValidProgression() const {
	if (size <= 0 || sequence[0] != first) return false;
	for (int i = 1; i < size; ++i) {
		if (sequence[i] - sequence[i-1] != difference) return false;
	}
	return true;
}

void ArithmeticProgression::print() const {
	std::cout << "Арифметическая прогрессия: ";
	for (int i = 0; i < size; ++i) {
		std::cout << sequence[i] << " ";
	}
	std::cout << std::endl;
}
