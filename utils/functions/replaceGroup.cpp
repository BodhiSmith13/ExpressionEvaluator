#include <string>

#include "replaceGroup.h"

#include <iostream>
#include <ostream>

#include "../values/debug.h"

std::string replaceGroup(std::string input, std::string targetGroup, const std::string& newGroup) {

    const std::string originalInput = input;

    if (DEBUG)
        std::cout << "Replacing group " << targetGroup << " with " << newGroup << " in input " << input << std::endl;

    int length = targetGroup.length();
    for (int i = 0; i < input.length(); i++) {

        if (input.substr(i, length) == targetGroup) {

            input.replace(i, length, newGroup);
            break;

        } // end of if statement

    } // end of for loop

    if (originalInput == input) {

        if (DEBUG)
            std::cout << "Unaltered input detected." << std::endl;

        for (int i = 0; i < input.length(); i++) {

            if ((targetGroup[i] == '+' || targetGroup[i] == '-' || targetGroup[i] == '*' || targetGroup[i] == '/')
                && i != 0) {

                targetGroup.insert(i, ".0");
                if (DEBUG)
                    std::cout << "Adding .0 to target group at index " << i << ", New Target Group: " << targetGroup
                << std::endl;
                return replaceGroup(input, targetGroup, newGroup);

            } // end of if statement

        } // end of for loop

    } // end of if statement

    return input;

} // end of replaceGroup