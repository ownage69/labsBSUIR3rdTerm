#pragma once
#include <string>
// јбстрактный класс "ћлекопитающее"
class Mammal {
protected:
	std::string name;
public:
	Mammal(const std::string& name = "Unnamed") : name(name) {}
	virtual ~Mammal() {}
	// „исто виртуальна€ функци€ описани€ Ч класс абстрактный
	virtual void describe() const = 0;
	std::string getName() const { return name; }
};
