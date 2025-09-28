#pragma once

#include <string>

class Mammal {
protected:
    std::string name;
    int age;

public:
    Mammal(const std::string& n, int a);
    virtual ~Mammal() = default;
    virtual void describe() const = 0;
};