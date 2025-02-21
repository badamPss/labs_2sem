#ifndef ARITHMETIC_PROGRESSION_H
#define ARITHMETIC_PROGRESSION_H

#include <iostream>
#include <stdexcept>

class ArithmeticProgression;

class InvalidProgressionException : public std::invalid_argument {
	const ArithmeticProgression* invalidProgression;

public:
	InvalidProgressionException(const std::string& message, const ArithmeticProgression* prog);
	void printError() const;
};

class ArithmeticProgression {
	double first;
	double difference;
	double* sequence;
	int size;

public:
	ArithmeticProgression(double first, double difference, double* arr, int size);
	~ArithmeticProgression();

	bool isValidProgression() const;
	void print() const;

	friend void InvalidProgressionException::printError() const;
};

#endif
