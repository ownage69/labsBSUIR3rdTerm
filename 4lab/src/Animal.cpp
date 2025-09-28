#include "Animal.h"
#include <iostream>
Animal::Animal(const std::string& name, int age)
	: Mammal(name), age(age) {
}
Animal::~Animal() {}
void Animal::describe() const {
	std::cout << "Животное: " << name << ", возраст: " << age << " лет." <<
		std::endl;
}
