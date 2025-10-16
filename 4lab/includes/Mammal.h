#pragma once
#include <string>

class Mammal {
private:
	std::string name;
public:
	explicit Mammal(const std::string& name = "Unnamed") : name(name) {}
	virtual ~Mammal() = default;

	virtual void describe() const = 0;
	std::string getName() const { return name; }
};