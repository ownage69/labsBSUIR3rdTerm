#pragma once
#include "Animal.h"

class Cat : public Animal {
protected:
    std::string color;
public:
    explicit Cat(const std::string& name = "Cat", int age = 0, const std::string& color = "Unknown");
    virtual ~Cat();
    void describe() const override;
};