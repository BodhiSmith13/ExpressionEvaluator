//
// Created by coops on 5/4/2026.
//

#include "findOperator.h"

#include <algorithm>
#include <iostream>

#include "indexNegativeNumbers.h"
#include "../values/debug.h"

#include <string>

int findOperator(const std::string& input, char op, int offset) {

    if (op == '-') {

        int index = input.find(op);

        std::vector<int> negativeIndexes = indexNegativeNumbers(input);
        if (std::find(negativeIndexes.begin(), negativeIndexes.end(), index) != negativeIndexes.end()) {

            offset += index + 1;

            if (DEBUG) {

                std::cout << "Skipping negative number at index " << index << ", starting new search at "
                << index + offset << std::endl;

            } // end of if statement

            return findOperator(input.substr(index + offset), op, offset);

        } else {

            if (DEBUG) {

                std::cout << "Found actual subtraction operator in string " << input << " at index "
                << index  << ", which is equal to index " << index + offset << " in the original string." << std::endl;

            } // end of if statement

            return index + offset;

        } // end of if else statement

    } // end of if statement

    if (DEBUG) {std::cout << "No subtraction, returning " << input.find(op) << std::endl;}
    return input.find(op);

} // end of function findOperator