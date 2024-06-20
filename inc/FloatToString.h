#pragma once

#include <string>
#include <sstream>
#include <iomanip>

std::string floatToString(float val, int decimalPlaces)
{
    std::stringstream ss;
    ss << std::fixed << std::setprecision(3) << val;
    return ss.str();
}