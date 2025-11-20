#pragma once

#include <stdexcept>
#include <string>

class StackException : public std::runtime_error
{
public:
    StackException() : std::runtime_error("Stack is empty") {}
    explicit StackException(const std::string& message) : std::runtime_error(message) {}
};

