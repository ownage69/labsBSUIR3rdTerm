#include "safeinput.h"
#include <iostream>
#include <regex>
#include <format>
#include <stdexcept>
#include <cctype>
#include <limits>

void trimInplace(std::string& s) {
    while (!s.empty() && std::isspace(static_cast<unsigned char>(s.front())))
        s.erase(s.begin());
    while (!s.empty() && std::isspace(static_cast<unsigned char>(s.back())))
        s.pop_back();
}

std::string readLineTrimmed(const std::string& prompt) {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    trimInplace(input);
    return input;
}

int safeInputInt(const std::string& prompt) {
    const std::regex pattern(R"(^[+-]?\d+$)");
    while (true) {
        std::string input = readLineTrimmed(prompt);
        if (!input.empty() && std::regex_match(input, pattern)) {
            try {
                return std::stoi(input);
            }
            catch (const std::invalid_argument&) {
                std::cout << std::format("Invalid input '{}'. Please enter a number.\n", input);
            }
            catch (const std::out_of_range&) {
                std::cout << std::format("Number '{}' is out of int range.\n", input);
            }
        }
        else {
            std::cout << "Error: enter an integer (optionally with + or - sign).\n";
        }
    }
}