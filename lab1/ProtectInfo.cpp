#include "ProtectInfo.hpp"

ProtectInfo::ProtectInfo() {
    name = "";
    type = "";
}

ProtectInfo::ProtectInfo(std::string& name, std::string& type) {
    this->name = name;
    this->type = type;
}

std::string ProtectInfo::getType() const {
    return type;
}

void ProtectInfo::print(std::ostream& out) const {
    out << "Метод: " << name << ", Тип: " << type << std::endl;
}
