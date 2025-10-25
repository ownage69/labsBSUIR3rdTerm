#pragma once
#include <exception>
#include <string>

using namespace std;

class InvalidCharacterException : public exception {
    string errormessage;
public:
    InvalidCharacterException(const string& input, const string& invalidChars) {
        errormessage = "������ �����: ������� ������������ �������: '" + invalidChars + "' � ������: \"" + input + "\"";
    }
    const char* what() const noexcept override {
        return errormessage.c_str();
    }
};