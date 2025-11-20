#include "safeInput.h"

#include <iostream>
#include <string>
#include <regex>
#include <cctype>

using std::string;
using std::cout;
using std::cin;
using std::getline;

inline void trimInPlace(string &s)
{
    while (!s.empty() && isspace(static_cast<unsigned char>(s.front())))
        s.erase(s.begin());
    while (!s.empty() && isspace(static_cast<unsigned char>(s.back())))
        s.pop_back();
}

std::string readLineTrimmed(const std::string &prompt)
{
    string input;
    cout << prompt;
    getline(cin, input);
    trimInPlace(input);
    return input;
}

int safeInputInt(const std::string &prompt)
{
    std::regex pattern(R"(^[+-]?\d+$)");
    while (true)
    {
        string input = readLineTrimmed(prompt);

        if (!input.empty() && std::regex_match(input, pattern))
        {
            try
            {
                return std::stoi(input);
            }
            catch (const std::invalid_argument &)
            {
                cout << "Invalid input. Please enter a number.\n";
            }
            catch (const std::out_of_range &)
            {
                cout << "Number is out of int range. Please enter again.\n";
            }
        }
        else
        {
            cout << "Invalid input. Please enter an integer.\n";
        }
    }
}

int safePositiveInputInt(const std::string &prompt)
{
    while (true)
    {
        if (int number = safeInputInt(prompt); number > 0)
            return number;
        cout << "Number must be positive\n";
    }
}

