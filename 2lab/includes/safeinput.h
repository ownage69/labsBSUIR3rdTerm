#pragma once

#include <string>

std::string readLineTrimmed(const std::string& prompt);
int safeInputInt(const std::string& prompt);
int safePositiveInputInt(const std::string& prompt);