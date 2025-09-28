#pragma once

#include "animal.h"
#include <string>

class Cat : public Animal {
private:
    std::string color;

public:
    Cat(const std::string& n, int a, const std::string& c);
    void describe() const override;
};