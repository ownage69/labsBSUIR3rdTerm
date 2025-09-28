#pragma once

#include "mammal.h"

class Animal : public Mammal {
public:
    Animal(const std::string& n, int a);
};