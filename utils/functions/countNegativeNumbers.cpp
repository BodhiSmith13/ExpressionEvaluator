//
// Created by coops on 5/3/2026.
//


#include <algorithm>
#include <array>
#include <string>
#include "../values/validOperators.h"

int countNegativeNumbers(const std::string& input) {

    int numNegatives = 0;
    for (int i = 0; i < input.length(); i++) {

        if (input[i] == '-') {

            if (i == 0
                || std::find(validOperators.begin(), validOperators.end(), input[i-1]) != validOperators.end())
                {numNegatives++;}

        } // end of if statement

    } // end of for loop

    return numNegatives;
} // end of countNegativeNumbers