#pragma once
#include "Animal.h"

class Dog : public Animal {
    std::string breed;
public:
    Dog(const std::string& name = "Dog", int age = 0, const std::string& breed = "Unknown");
    virtual ~Dog() = default;
    void describe() const override;
};