#pragma once
#include <string>

class Mammal {
    std::string name;
public:
    explicit Mammal(const std::string& name = "Unnamed") : name(name) {}
    virtual ~Mammal() {}

    virtual void describe() const = 0;
    std::string getName() const { return name; }
};