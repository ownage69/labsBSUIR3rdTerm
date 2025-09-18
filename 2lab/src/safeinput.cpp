#include "SafeInput.h"
#include <iostream>
#include <string>
#include <regex>
#include <cctype>

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
    static const std::regex pat(R"(^[+-]?\d+$)");

    while (true) {
        string input = readLineTrimmed(prompt);

        if (!input.empty() && std::regex_match(input, pat)) {
            try {
                long val = std::stol(input);
                if (val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max()) {
                    cout << "Число вне диапазона int. Введите заново.\n";
                    continue;
                }
                return static_cast<int>(val);
            }
            catch (const std::invalid_argument&) {
                cout << "Некорректный ввод. Введите число.\n";
            }
            catch (const std::out_of_range&) {
                cout << "Число вне допустимого диапазона. Введите заново.\n";
            }
        }
        else {
            cout << "Некорректный ввод. Введите целое число\n";
        }
    }
}

int safePositiveInputInt(const string& prompt) {
    while (true) {
        if (int number = safeInputInt(prompt); number > 0)
            return number;
        cout << "Число должно быть положительным\n";
    }
}
