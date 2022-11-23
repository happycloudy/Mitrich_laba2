//
// Created by Artur1337 on 23.11.2022.
//

#ifndef LABA2_GENNUMBERS_H
#define LABA2_GENNUMBERS_H

#include <random>
#include <algorithm>
#include <iostream>
#include <iterator>

double genNumbers() {
    static std::mt19937 gen(time(nullptr));
    std::uniform_int_distribution<> dist(-100, 100);
    return dist(gen);
}

#endif //LABA2_GENNUMBERS_H
