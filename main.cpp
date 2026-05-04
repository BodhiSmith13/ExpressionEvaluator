#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>

#include "utils/functions/findPair.h"
#include "utils/functions/replaceGroup.h"
#include "utils/functions/doubleToCleanString.h"
#include "utils/values/debug.h"
#include "utils/functions/countNegativeNumbers.h"
#include "utils/functions/findOperator.h"
#include "utils/functions/indexNegativeNumbers.h"
#include "utils/values/validOperators.h"


int main() {

    DEBUG = true;

    if (!DEBUG) {

        std::string choice;

        std::cout << "Would you like to enable debug messages? Enter y for yes, n for no: ";
        std::cin >> choice;

        if (choice == "y") {DEBUG = true;}

    } // end of if statement

    std::string input;
    std::cout << "Enter an expression: ";
    std::cin >> input;
    Pair pair;
    int negativeNum = countNegativeNumbers(input);

    int numOps = std::count(input.begin(), input.end(), '*')
    + std::count(input.begin(), input.end(), '/')
    + std::count(input.begin(), input.end(), '+')
    + std::count(input.begin(), input.end(), '-')
    - negativeNum;

    if (DEBUG) {

        std::cout << "Number of multiplication operators: " << std::count(input.begin(), input.end(), '*')
        << std::endl;
        std::cout << "Number of division operators: " << std::count(input.begin(), input.end(), '/')
        << std::endl;
        std::cout << "Number of addition operators: " << std::count(input.begin(), input.end(), '+')
        << std::endl;
        std::cout << "Number of subtraction operators: " << std::count(input.begin(), input.end(), '-')
         - negativeNum << std::endl;
        std::cout << "Number of negative numbers: " << negativeNum << std::endl;
        std::cout << "Total number of operators: " << numOps << std::endl;

    } // end of if statement

    for (int i = 0; i < numOps; i++) {
        bool opFound = false;

            for (int i = 0; i < input.length(); i++) {

                if (input[i] == '*' || input[i] == '/') {

                    if (input[i] == '*') {

                        if (DEBUG) {std::cout << "Multiplication detected." << std::endl;}
                        pair = findPair(input, i);
                        input = replaceGroup(input, pair.getPair(),
                            doubleToCleanString(pair.simplify()));
                        if (DEBUG) {std::cout << "Input after replacement: " << input << std::endl;}
                        opFound = true;
                        break;

                    } // end of if statement

                    if (input[i] == '/') {

                        if (DEBUG) {std::cout << "Division detected." << std::endl;}
                        pair = findPair(input, i);
                        input = replaceGroup(input, pair.getPair(),
                            doubleToCleanString(pair.simplify()));
                        if (DEBUG) {std::cout << "Input after replacement: " << input << std::endl;}
                        opFound = true;
                        break;

                    } // end of if statement

                } // end of if statement

            } // end of for loop

            if (!opFound) {

                for (int i = 0; i < input.length(); i++) {

                    if (input[i] == '+' || input[i] == '-') {

                        if (input[i] == '+') {

                            if (DEBUG) {std::cout << "Addition detected." << std::endl;}
                            pair = findPair(input, i);
                            input = replaceGroup(input, pair.getPair(),
                                doubleToCleanString(pair.simplify()));
                            if (DEBUG) {std::cout << "Input after replacement: " << input << std::endl;}
                            break;

                        } // end of if statement

                        if (input[i] == '-' && i != 0
                        && std::find(validOperators.begin(), validOperators.end(), input[i-1])
                        == validOperators.end()) {

                            if (DEBUG) {std::cout << "Subtraction detected at " << i << std::endl;}
                            pair = findPair(input, i);
                            input = replaceGroup(input, pair.getPair(),
                                doubleToCleanString(pair.simplify()));
                            if (DEBUG) {std::cout << "Input after replacement: " << input << std::endl;}
                            break;

                        } // end of if statement

                    } // end of if statement

                } // end of for loop

            } // end of if statement



    } // end of for loop

} // end of main