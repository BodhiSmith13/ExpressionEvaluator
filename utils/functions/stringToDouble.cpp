//
// Created by coops on 5/3/2026.
//

#include <iostream>
#include <string>

#include "stringToDouble.h"

double stringToDouble(std::string input) {

    std::cout << input[0] << std::endl;
    if (input[0] ==  '-') {
        std::cout << "Negative number detected" << std::endl;
        return std::stod(input.substr(1, input.length() - 1)) * -1;
    }

    return std::stod(input);

}
