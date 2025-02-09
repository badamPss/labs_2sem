#ifndef PROTECTINFO_HPP
#define PROTECTINFO_HPP

#include <iostream>
#include <string>

class ProtectInfo {

    std::string name;
    std::string type;

public:

    ProtectInfo();

    explicit ProtectInfo(std::string& name, std::string& type);

    std::string getType() const;
    void print(std::ostream& out) const;

};

#endif
