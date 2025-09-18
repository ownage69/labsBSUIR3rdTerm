#pragma once

#include "array.h"
#include "SafeInput.h"
#include <string>

void createArray(Array& arr, const std::string& name);
void printArray(const Array& arr, const std::string& name);
void concatenateArrays(const Array& a, const Array& b);
void showMenu();