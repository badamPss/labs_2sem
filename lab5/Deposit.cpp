#include "Deposit.h"

Deposit::Deposit() {
	this->name = "";
	this->amount = 0;
	this->type = "";
	this->rate = 0;
}

Deposit::Deposit(std::string &name, double amount, std::string &type, double rate) {
	this->name = name;
	this->amount = amount;
	this->type = type;
	this->rate = rate;
}

std::ostream& operator<<(std::ostream& out, const Deposit& deposit) {
	out << "Название: " << deposit.name << "; Сумма вклада: " << deposit.amount << "; Тип валюты: " << deposit.type << "; Ставка: " << deposit.rate << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, Deposit& deposit) {
	in >> deposit.name >> deposit.amount >> deposit.type >> deposit.rate;
	return in;
}

bool Deposit::operator<(const Deposit& other) const {
	return this->amount < other.amount;
}

bool operator==(const Deposit& lhs, const Deposit& rhs) {
	return lhs.name == rhs.name && lhs.amount == rhs.amount && lhs.type == rhs.type && lhs.rate == rhs.rate;
}
