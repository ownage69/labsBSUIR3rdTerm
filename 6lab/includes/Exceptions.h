#pragma once
#include <exception>
#include <string>

using namespace std;

class InvalidCharacterException : public exception {
    string message_;
public:
    InvalidCharacterException(const string& input, const string& invalidChars) {
        message_ = "������ �����: ������� ������������ �������: '" + invalidChars + "' � ������: \"" + input + "\"";
    }
    const char* what() const noexcept override {
        return message_.c_str();
    }
};