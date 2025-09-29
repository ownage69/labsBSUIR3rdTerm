#pragma once
#include "Animal.h"

class Dog : public Animal {
    std::string breed;
public:
    explicit Dog(const std::string& name = "Dog", int age = 0, const std::string& breed = "Unknown");
    ~Dog() override = default;
    void describe() const override;
};