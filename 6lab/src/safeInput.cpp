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
        std::set<char> invalidSet;
        bool first = true;
        for (char ch : input) {
            unsigned char uch = static_cast<unsigned char>(ch);
            if (first) {
                if (!(uch == '+' || uch == '-' || (uch >= '0' && uch <= '9'))) {
                    invalidSet.insert(ch);
                }
                first = false;
            }
            else {
                if (!(uch >= '0' && uch <= '9')) {
                    invalidSet.insert(ch);
                }
            }
        }
        std::string invalidChars;
        for (char ch : invalidSet) {
            if (std::isprint(static_cast<unsigned char>(ch))) {
                invalidChars.push_back(ch);
            }
            else {
                invalidChars += '[';
                invalidChars += std::to_string(static_cast<unsigned char>(ch));
                invalidChars += ']';
            }
        }
        if (!invalidChars.empty()) {
            throw InvalidCharacterException(input, invalidChars);
        }
        throw std::invalid_argument("Некорректный формат числа");
    }
}