#ifndef PROTECTINFO_HPP
#define PROTECTINFO_HPP

#include <string>
#include <ostream>

class ProtectInfo {
    std::string name;
    std::string type;

public:
    ProtectInfo();
    explicit ProtectInfo(const std::string& name, const std::string& type);
    std::string getType() const;
    void print(std::ostream& out) const;
};

#endif