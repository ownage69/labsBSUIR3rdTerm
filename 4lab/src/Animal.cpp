#include "Animal.h"
#include <iostream>

Animal::Animal(const std::string& name, int age)
    : Mammal(name), age(age) {
}
void Animal::describe() const {
    std::cout << "Animal: " << getName() << ", age: " << getAge() << " years." << std::endl;
}