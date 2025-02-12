#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <string>
#include <iostream>

class Deposit {
public:
	std::string name;
	double amount;
	std::string type;
	double rate;

	Deposit();
	Deposit(std::string& name, double amount, std::string& type, double rate);

	friend std::ostream& operator<<(std::ostream& os, const Deposit& d);
	friend std::istream& operator>>(std::istream& is, Deposit& d);

	bool operator<(const Deposit& other) const;
};

#endif
