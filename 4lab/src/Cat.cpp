#include "Cat.h"
#include <iostream>


Cat::Cat(const std::string& name, int age, const std::string& color)
	: Animal(name, age), color(color) {
}


Cat::~Cat() {}


void Cat::describe() const {
	std::cout << "���: " << name << ", �����: " << color << ", �������: " << age << " ���." << std::endl;
}