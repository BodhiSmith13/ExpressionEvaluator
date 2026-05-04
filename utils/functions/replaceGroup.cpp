#include <string>

#include "replaceGroup.h"

std::string replaceGroup(std::string input, const std::string& targetGroup, const std::string& newGroup) {

    int length = targetGroup.length();
    for (int i = 0; i < input.length(); i++) {

        if (input.substr(i, length) == targetGroup) {
            input.replace(i, length, newGroup);
            break;
        }

    } // end of for loop

    return input;

} // end of replaceGroup