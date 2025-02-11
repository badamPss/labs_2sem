#include "Circle.h"
#include <iostream>

int main() {
	Circle circle(5.0);
	Sphere sphere(5.0);

	std::cout << "Статический полиморфизм" << std::endl;
	circle.print();
	sphere.print();

	std::cout << "\nДинамический полиморфизм" << std::endl;
	Circle* shape1 = &circle;
	Circle* shape2 = &sphere;

	shape1->print();
	shape2->print();

	return 0;
}
