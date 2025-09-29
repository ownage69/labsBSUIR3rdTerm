#pragma once
#include "Mammal.h"

class Animal : public Mammal {
protected:
    int age;
public:
    explicit Animal(const std::string& name = "Unnamed", int age = 0);
    virtual ~Animal();

    virtual void describe() const override;
    int getAge() const { return age; }
};