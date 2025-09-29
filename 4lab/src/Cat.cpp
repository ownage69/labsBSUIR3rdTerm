#include "Cat.h"
#include <iostream>

Cat::Cat(const std::string& name, int age, const std::string& color)
    : Animal(name, age), color(color) {
}

void Cat::describe() const {
    std::cout << "Cat: " << getName() << ", color: " << color << ", age: " << getAge() << " years." << std::endl;
}