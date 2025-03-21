#include "ProtectInfo.hpp"

ProtectInfo::ProtectInfo() : name(""), type("") {}

ProtectInfo::ProtectInfo(const std::string& name, const std::string& type)
    : name(name), type(type) {}

std::string ProtectInfo::getType() const {
    return type;
}

void ProtectInfo::print(std::ostream& out) const {
    out << "Метод: " << name << ", Тип: " << type << std::endl;
}