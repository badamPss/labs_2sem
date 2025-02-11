#include "Circle.h"
#include <math.h>
#include <iostream>

Circle::Circle(double radius) {
	this->radius = radius;
}

double Circle::getArea() {
	return M_PI * radius * radius;
}

void Circle::print() {
	std::cout << "Круг: радиус = " << radius << ", площадь = " << getArea() << std::endl;
}

Sphere::Sphere(double radius) : Circle(radius) {}

double Sphere::getArea() {
	return (4.0 / 3.0) * M_PI * pow(radius, 3);
}

void Sphere::print() {
	std::cout << "Шар: радиус = " << radius << ", объем = " << getArea() << std::endl;
}
