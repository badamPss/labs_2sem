#include "ArithmeticProgression.h"

int main() {
	try {
		double* arr = new double[5]{1, 3, 5, 7, 9};
		ArithmeticProgression ap1(1, 2, arr, 5);
		ap1.print();
	} catch (const InvalidProgressionException& e) {
		e.printError();
	}

	std::cout << std::endl;

	try {
		double* arr = new double[5]{1, 4, 5, 7, 9};
		ArithmeticProgression ap2(1, 2, arr, 5);
		ap2.print();
	} catch (const InvalidProgressionException& e) {
		e.printError();
	}

	return 0;
}
