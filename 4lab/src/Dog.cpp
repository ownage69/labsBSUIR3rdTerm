#include "Dog.h"
#include <iostream>

Dog::Dog(const std::string& name, int age, const std::string& breed)
    : Animal(name, age), breed(breed) {
}
Dog::~Dog() {}
void Dog::describe() const {
    std::cout << "Dog: " << name << ", breed: " << breed << ", age: " << age << " years." << std::endl;
}