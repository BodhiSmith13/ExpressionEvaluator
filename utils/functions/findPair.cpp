#include "findPair.h"
#include "../classes/Pair.h"
#include "../values/debug.h"
#include "../values/validOperators.h"

#include <array>
#include <algorithm>
#include <iostream>
#include <ostream>

std::array<char, 2> groupings = {'(', ')'};

Pair findPair(std::string input, int index) {

    char op = input[index];
    if (DEBUG) {std::cout << "Operator " << op << " found at index " << index << std::endl;}

    std::string operand1;
    std::string operand2;

    if (DEBUG) {std::cout << "Beginning search for operand1 at " << index - 1 << std::endl;}

    for (int i = index - 1; i >= 0; i--) {

        if ( input[i] == '-' && (i == 0
            ||std::find(validOperators.begin(), validOperators.end(), input[i-1]) != validOperators.end())) {

            if (DEBUG) {std::cout << "Negative number found at index " << i << std::endl;}
            operand1 += input[i];
            break;

        } // end of if statement

        if (std::find(groupings.begin(), groupings.end(), input[i-1]) != groupings.end()
            && std::find(validOperators.begin(), validOperators.end(), input[i]) == validOperators.end()) {

            if (DEBUG) {std::cout << "Found final digit of operand1: " << input[i] << std::endl;}
            operand1 += input[i];
            break;

            } // end of if statement

        if (std::isdigit(input[i]) || input[i] == '.') {

            if (DEBUG) {std::cout << "Found  digit of operand1: " << input[i] << std::endl;}
            operand1 += input[i];

        } // end of if statement

        else if (std::find(validOperators.begin(), validOperators.end(), input[i]) != validOperators.end()) {

            if (DEBUG) {std::cout << "Found beginning of another operation, ending operand1: " << input[i] << std::endl;}
            break;

        }

    } // end of for loop

    if (DEBUG) {std::cout << "Beginning search for operand2 at " << index + 1 << std::endl;}

    for (int i = index + 1; i < input.length(); i++) {

        if (std::find(groupings.begin(), groupings.end(), input[i]) != groupings.end()
            && i == input.length() - 1) {break;}

        if (std::find(groupings.begin(), groupings.end(), input[i+1]) != groupings.end()
            && std::find(validOperators.begin(), validOperators.end(), input[i]) == validOperators.end()) {

            if (DEBUG) {std::cout << "Found final digit of operand2: " << input[i] << std::endl;}
            operand2 += input[i];
            break;

            }

        if (std::isdigit(input[i]) || input[i] == '.') {

            if (DEBUG) {std::cout << "Found digit of operand2: " << input[i] << std::endl;}
            operand2 += input[i];

        } else if ( input[i] == '-' && (i == 0
            ||std::find(validOperators.begin(), validOperators.end(), input[i-1]) != validOperators.end())) {

                if (DEBUG) {std::cout << "Negative number found at index " << i << std::endl;}
                operand2 += input[i];

        }

        else if (std::find(validOperators.begin(), validOperators.end(), input[i]) != validOperators.end()) {

            if (DEBUG) {std::cout << "Found beginning of another operation: " << input[i] << std::endl;}
            break;

        } // end of if statement

    } // end of for loop

    std::reverse(operand1.begin(), operand1.end());

    if (DEBUG) {

        std::cout << "Operand1: " << operand1 << std::endl;
        std::cout << "Operand2: " << operand2 << std::endl;

    }

    Pair output(std::stod(operand1), std::stod(operand2), op);
    return output;

} // end of findPair