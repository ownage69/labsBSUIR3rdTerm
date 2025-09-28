#pragma once
#include "Animal.h"
//  ласс "—обака" Ч производный от Animal
class Dog : public Animal {
	std::string breed;
public:
	Dog(const std::string& name = "Dog", int age = 0, const std::string&
		breed = "Unknown");
	virtual ~Dog();
		void describe() const override;
};
