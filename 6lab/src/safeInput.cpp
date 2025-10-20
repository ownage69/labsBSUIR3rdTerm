#include "safeInput.h"
#include "Exceptions.h"
#include <iostream>
#include <string>
#include <regex>
#include <cctype>
#include <set>

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
    string input = readLineTrimmed(prompt);
    if (input.empty()) {
        throw InvalidCharacterException(input, "Пустая строка");
    }
    if (std::regex_match(input, pat)) {
        try {
            return std::stoi(input);
        }
        catch (const std::out_of_range&) {
            throw std::out_of_range("Число вне диапазона int");
        }
    }
    else {
        auto invalidSet = std::set<char>{};
        for (size_t i = 0; i < input.size(); ++i) {
            char ch = input[i];
            unsigned char uch = static_cast<unsigned char>(ch);
            bool is_valid = (i == 0 && (uch == '+' || uch == '-')) || (uch >= '0' && uch <= '9');
            if (!is_valid) {
                invalidSet.insert(ch);
            }
        }
        auto invalidChars = std::string{};
        for (char ch : invalidSet) {
            unsigned char uch = static_cast<unsigned char>(ch);
            if (std::isprint(uch)) {
                invalidChars.push_back(ch);
            }
            else {
                invalidChars += '[';
                invalidChars += std::to_string(uch);
                invalidChars += ']';
            }
        }
        if (!invalidChars.empty()) {
            throw InvalidCharacterException(input, invalidChars);
        }
        throw std::invalid_argument("Некорректный формат числа");
    }
}