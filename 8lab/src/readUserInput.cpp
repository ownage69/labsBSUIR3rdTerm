#include "readUserInput.h"

template <>
std::string readUserInput<std::string>(const std::string &prompt)
{
    std::string inputValue;
    std::cout << prompt;
    std::getline(std::cin, inputValue);
    return inputValue;
}

