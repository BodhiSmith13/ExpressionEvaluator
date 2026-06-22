//
// Created by coops on 5/3/2026.
//

#include <iostream>
#include <string>

#include "stringToDouble.h"

#include "../values/debug.h"

double stringToDouble(const std::string &input) {

    if (DEBUG)
        std::cout << input[0] << std::endl;
    if (input[0] ==  '-') {
        if (DEBUG)
            std::cout << "Negative number detected" << std::endl;
        return std::stod(input.substr(1, input.length() - 1)) * -1;
    }

    return std::stod(input);

}
