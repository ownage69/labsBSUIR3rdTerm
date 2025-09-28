#pragma once
#include "Animal.h"
// Класс "Кот" — производный от Animal
class Cat : public Animal {
	std::string color;
public:
	Cat(const std::string& name = "Cat", int age = 0, const std::string&
		color = "Unknown");
	virtual ~Cat();
	void describe() const override;
};