#pragma once
#include "Mammal.h"

class Human : public Mammal {
    std::string profession;
    int age;
public:
    Human(const std::string& name = "Unnamed", int age = 0, const std::string& profession = "None");
    virtual ~Human();
    void describe() const override;
};