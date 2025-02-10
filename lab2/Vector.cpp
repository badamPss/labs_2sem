#include "Vector.hpp"

Vector::Vector() {
  	data = nullptr;
  	size = 0;
}

Vector::Vector(unsigned int size, const double* data) {
  	this->size = size;
  	this->data = new double[size];
  	for (unsigned int i = 0; i < size; i++) {
    	this->data[i] = data[i];
  	}
}

Vector::~Vector() {
  	delete[] data;
}

Vector::Vector(const Vector& other) {
  	size = other.size;
  	data = new double[size];
  	for (unsigned int i = 0; i < size; i++) {
    	data[i] = other.data[i];
  	}
}

Vector::Vector(Vector&& other) noexcept {
    data = other.data;
    size = other.size;
    other.data = nullptr;
    other.size = 0;
}

double& Vector::operator[](unsigned int index) {
    return data[index];
}

Vector& Vector::operator=(const Vector& other) {
	if (this != &other) {
        delete[] data;
        size = other.size;
        data = new double[size];
        for (unsigned i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

Vector& Vector::operator=(Vector&& other) noexcept {
	if (this != &other) {
        delete[] data;
        data = other.data;
        size = other.size;
        other.data = nullptr;
        other.size = 0;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Vector& v) {
  	for (unsigned int i = 0; i < v.size; i++) {
    	out << v.data[i] << " ";
  	}
  	return out;
}

std::istream& operator>>(std::istream& in, Vector& v) {
  	in >> v.size;
    delete[] v.data;
    v.data = new double[v.size];
    for (unsigned i = 0; i < v.size; ++i) {
        in >> v.data[i];
    }
    return in;
}

Vector Vector::operator+(const Vector& other) {
    unsigned newSize = size + other.size;
    double* newData = new double[newSize];

    for (unsigned i = 0; i < size; ++i) {
        newData[i] = data[i];
    }
    for (unsigned i = 0; i < other.size; ++i) {
        newData[size + i] = other.data[i];
    }

    return Vector(newSize, newData);
}

Vector Vector::operator+(const double* arr) {
    return *this + Vector(size, arr);
}