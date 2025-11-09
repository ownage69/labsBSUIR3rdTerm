#pragma once
#include <exception>
#include <string>

class OutOfRangeException : public std::exception {
    std::string message;

public:
    explicit OutOfRangeException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};