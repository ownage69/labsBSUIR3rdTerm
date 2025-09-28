#include "Cat.h"
#include <iostream>


Cat::Cat(const std::string& name, int age, const std::string& color)
	: Animal(name, age), color(color) {
}


Cat::~Cat() {}


void Cat::describe() const {
	std::cout << "Кот: " << name << ", окрас: " << color << ", возраст: " << age << " лет." << std::endl;
}