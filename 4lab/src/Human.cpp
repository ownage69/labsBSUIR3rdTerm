#include "human.h"
#include <iostream>

Human::Human(const std::string& n, int a, const std::string& p) : Mammal(n, a), profession(p) {}

void Human::describe() const {
    std::cout << "Hello! I am a human named " << name << ", age " << age << ", working as a " << profession << "." << std::endl;
}