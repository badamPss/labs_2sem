#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

class Vector {

    double* data;
    unsigned int size;

public:
  	Vector();
  	Vector(unsigned int size, const double* data);
  	~Vector();

  	Vector(const Vector& other); //copy
  	Vector(Vector&& other) noexcept; //move

  	double& operator[](unsigned int index);
  	Vector& operator=(const Vector& other);
  	Vector& operator=(Vector&& other) noexcept;

  	friend std::ostream& operator<<(std::ostream& os, const Vector& v);
  	friend std::istream& operator>>(std::istream& is, Vector& v);

    Vector operator+(const Vector& other);
	Vector operator+(const double* other);
};

#endif
