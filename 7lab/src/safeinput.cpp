#include "safeinput.h"
#include <iostream>
#include <string>
#include <regex>
#include <cctype>
#include <limits>

using std::string;
using std::cout;
using std::cin;
using std::getline;

inline void trimInPlace(string& s) {
    while (!s.empty() && isspace(static_cast<unsigned char>(s.front())))
        s.erase(s.begin());
    while (!s.empty() && isspace(static_cast<unsigned char>(s.back())))
        s.pop_back();
}
string readLineTrimmed(const string& prompt) {
    string input;
    cout << prompt;
    getline(cin, input);
    trimInPlace(input);
    return input;
}
int safeInputInt(const string& prompt) {
    std::regex pat(R"(^[+-]?\d+$)");
    while (true) {
        string input = readLineTrimmed(prompt);
        if (!input.empty() && std::regex_match(input, pat)) {
            try {
                return std::stoi(input);
            }
            catch (const std::invalid_argument&) {
                cout << "Invalid input. Enter a number.\n";
            }
            catch (const std::out_of_range&) {
                cout << "Number out of int range. Try again.\n";
            }
        }
        else {
            cout << "Invalid input. Enter an integer.\n";
        }
    }
}
int safePositiveInputInt(const string& prompt) {
    while (true) {
        int number = safeInputInt(prompt);
        if (number > 0)
            return number;
        cout << "Number must be positive.\n";
    }
}
int safeNonNegativeInputInt(const string& prompt) {
    while (true) {
        int number = safeInputInt(prompt);
        if (number >= 0)
            return number;
        cout << "Number must be non-negative.\n";
    }
}
std::string safeInputString(const std::string& prompt) {
    while (true) {
        std::string input = readLineTrimmed(prompt);
        if (!input.empty()) {
            return input;
        }
        cout << "Input cannot be empty.\n";
    }
}