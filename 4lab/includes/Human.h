#pragma once

#include "mammal.h"
#include <string>

class Human : public Mammal {
private:
    std::string profession;

public:
    Human(const std::string& n, int a, const std::string& p);
    void describe() const override;
};