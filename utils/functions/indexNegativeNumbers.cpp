//
// Created by coops on 5/4/2026.
//

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#include "countNegativeNumbers.h"
#include "../values/validOperators.h"
#include "../values/debug.h"
#include "indexNegativeNumbers.h"

std::vector<int> indexNegativeNumbers(const std::string& input) {

    std::vector<int> indexNegativeNumbers;
    int negativeNum = countNegativeNumbers(input);
    int foundNegativeNum = 0;

    for (int i = 0; i < input.length(); i++) {

        if (input[i] == '-') {

            if (i == 0
                || std::find(validOperators.begin(), validOperators.end(), input[i-1]) != validOperators.end())
                {

                foundNegativeNum++;
                indexNegativeNumbers.push_back(i);

            } // end of if statement

        } // end of if statement

        if (foundNegativeNum == negativeNum) {

            if (DEBUG) {

                std::cout << "Found " << negativeNum << " negative numbers in " << input << " at indexes: ";
                for (int i = 0; i < indexNegativeNumbers.size(); i++) {std::cout << indexNegativeNumbers[i] << " ";}
                std::cout << std::endl;

            } // end of if statement
            return indexNegativeNumbers;

        } // end of if statement

    } // end of for loop

} // end of function indexNegativeNumbers
