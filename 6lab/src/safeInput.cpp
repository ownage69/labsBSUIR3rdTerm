#include "safeInput.h"
#include "EmptyInputException.h"
#include "InvalidCharacterException.h"
#include "OutOfRangeException.h"
#include "InvalidFormatException.h"
#include <iostream>
#include <string>
#include <regex>
#include <set>
#include <cctype>

using std::string;
using std::getline;
inline void trimInPlace(string& s) {
    while (!s.empty() && isspace(static_cast<unsigned char>(s.front())))
        s.erase(s.begin());
    while (!s.empty() && isspace(static_cast<unsigned char>(s.back())))
        s.pop_back();
}

string readLineTrimmed(const string& prompt) {
    string input;
    std::cout << prompt;
    getline(std::cin, input);
    trimInPlace(input);
    return input;
}

int safeInputInt(const string& prompt) {
    string input = readLineTrimmed(prompt);
    std::regex pat(R"(^[+-]?\d+$)");
    if (input.empty()) {
        throw EmptyInputException(input);
    }
    if (std::regex_match(input, pat)) {
        try {
            return std::stoi(input);
        }
        catch (const std::out_of_range&) {
            throw OutOfRangeException("Число вне диапазона int");
        }
    }
    std::set<char> invalid;
    for (size_t i = 0; i < input.size(); i++) {
        char ch = input[i];
        auto uch = static_cast<unsigned char>(ch);
        bool valid = (i == 0 && (uch == '+' || uch == '-')) || (uch >= '0' && uch <= '9');
        if (!valid) invalid.insert(ch);
    }
    if (!invalid.empty()) {
        string bad;
        for (char x : invalid) bad += x;
        throw InvalidCharacterException(input, bad);
    }
    throw InvalidFormatException("Некорректный формат числа");
}