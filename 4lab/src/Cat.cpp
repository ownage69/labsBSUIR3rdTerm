#include "cat.h"
#include <iostream>

Cat::Cat(const std::string& n, int a, const std::string& c) : Animal(n, a), color(c) {}

void Cat::describe() const {
    std::cout << "Meow! I'm a cat named " << name << ", age " << age << ", with " << color << " fur." << std::endl;
}