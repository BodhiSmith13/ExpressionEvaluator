cmake_minimum_required(VERSION 4.0)
project(ExpressionEvaluator)

set(CMAKE_CXX_STANDARD 14)

add_executable(ExpressionEvaluator main.cpp
        utils/functions/replaceGroup.cpp
        utils/functions/findPair.cpp
        utils/functions/findPair.h
        utils/classes/Pair.cpp
        utils/functions/replaceGroup.h
        utils/functions/doubleToCleanString.cpp
        utils/functions/doubleToCleanString.h
        utils/functions/stringToDouble.cpp
        utils/functions/stringToDouble.h
        utils/values/debug.cpp
        utils/values/debug.h
        utils/functions/countNegativeNumbers.cpp
        utils/functions/countNegativeNumbers.h
        utils/values/validOperators.cpp
        utils/values/validOperators.h
        utils/functions/indexNegativeNumbers.cpp
        utils/functions/indexNegativeNumbers.h
        utils/functions/findOperator.cpp
        utils/functions/findOperator.h
)
