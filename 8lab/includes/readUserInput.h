#pragma once

#include <iostream>
#include <limits>
#include <string>

template <typename T>
T readUserInput(const std::string &prompt)
{
    T inputValue;
    while (true)
    {
        std::cout << prompt;
        std::cin >> inputValue;

        if (std::cin.fail())
        {
            std::cout << "Error! Please enter a valid value." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return inputValue;
        }
    }
}

template <>
std::string readUserInput<std::string>(const std::string &prompt);
