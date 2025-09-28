#include "dog.h"
#include <iostream>

Dog::Dog(const std::string& n, int a, const std::string& b) : Animal(n, a), breed(b) {}

void Dog::describe() const {
    std::cout << "Woof! I'm a dog named " << name << ", age " << age << ", of breed " << breed << "." << std::endl;
}