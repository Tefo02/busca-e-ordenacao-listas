#pragma once

#include <iostream>

#include "ArrayList.hpp"
#include "SimpleList.hpp"
#include "DoubleList.hpp"

enum class ListType {
    QUIT = 0,
    ARRAY_LIST = 1,
    SIMPLE_LIST = 2,
    DOUBLE_LIST = 3
};

enum class Option {
    QUIT = 0,
    GET_LIST = 1,
    GENERATE_RANDOM_LIST = 2,
    INSERT_AT = 3,
    SWAP_VALUE = 4,
    SEARCH = 5,
    FIND_MIN = 6,
    PRINT = 7,
    PRINT_REVERSE = 8
};

enum ListType menu();
enum Option submenu(const ListType& listType);

int getInt(const std::string& message);
unsigned getUnsigned(const std::string& message);