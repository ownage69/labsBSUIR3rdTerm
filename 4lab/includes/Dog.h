#pragma once

#include "animal.h"
#include <string>

class Dog : public Animal {
private:
    std::string breed;

public:
    Dog(const std::string& n, int a, const std::string& b);
    void describe() const override;
};