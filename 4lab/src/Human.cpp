#include "Human.h"
#include <iostream>
Human::Human(const std::string& name, const std::string& profession)
	: Mammal(name), profession(profession) {
}
Human::~Human() {}
void Human::describe() const {
	std::cout << "�������: " << name << ", ���������: " << profession << "."
		<< std::endl;
}
