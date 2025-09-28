#pragma once
#include "Mammal.h"
//  ласс "∆ивотное" Ч производный от Mammal
class Animal : public Mammal {
protected:
	int age;
public:
	Animal(const std::string& name = "Unnamed", int age = 0);
	virtual ~Animal();
	// ѕо умолчанию животное даЄт простое описание Ч можно переопределить
	virtual void describe() const override;
	int getAge() const { return age; }
};