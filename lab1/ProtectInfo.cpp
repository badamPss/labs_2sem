#include "ProtectInfo.hpp"

ProtectInfo::ProtectInfo() : name(""), type("") {}

ProtectInfo::ProtectInfo(std::string& name, std::string& type)
    : name(name), type(type) {}

std::string ProtectInfo::getType() const {
    return type;
}

void ProtectInfo::print(std::ostream& out) const {
    out << "Метод: " << name << ", Тип: " << type << std::endl;
}
