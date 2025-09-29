#pragma once
#include "Animal.h"

class Cat : public Animal {
    std::string color;
public:
    explicit Cat(const std::string& name = "Cat", int age = 0, const std::string& color = "Unknown");
    ~Cat() override = default;
    void describe() const override;
};