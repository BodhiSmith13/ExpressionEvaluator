//
// Created by coops on 5/3/2026.
//

#include <sstream>

std::string doubleToCleanString(double value) {
    std::ostringstream oss;
    oss << std::noshowpoint << value;
    return oss.str();
}