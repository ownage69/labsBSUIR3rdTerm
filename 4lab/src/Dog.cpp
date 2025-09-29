#include "Dog.h"
#include <iostream>

Dog::Dog(const std::string& name, int age, const std::string& breed)
    : Animal(name, age), breed(breed) {
}
void Dog::describe() const {
    std::cout << "Dog: " << getName() << ", breed: " << breed << ", age: " << getAge() << " years." << std::endl;
}