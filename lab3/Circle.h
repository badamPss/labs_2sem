#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
protected:
	double radius;

public:
	Circle(double radius);
	virtual ~Circle() = default;

	virtual double getArea();
	virtual void print();
};

class Sphere : public Circle {
public:
	Sphere(double radius);
	double getArea();
	void print();
};

#endif
