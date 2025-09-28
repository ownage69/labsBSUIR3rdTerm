#pragma once
#include "Animal.h"
// ����� "���" � ����������� �� Animal
class Cat : public Animal {
	std::string color;
public:
	Cat(const std::string& name = "Cat", int age = 0, const std::string&
		color = "Unknown");
	virtual ~Cat();
	void describe() const override;
};