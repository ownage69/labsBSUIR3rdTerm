#include "Human.h"
#include <iostream>

Human::Human(const std::string& name, int age, const std::string& profession)
    : Mammal(name), profession(profession), age(age) {
}
void Human::describe() const {
    std::cout << "Human: " << getName() << ", age: " << age << " years, profession: " << profession << "." << std::endl;
}