//
// Created by Artur1337 on 23.11.2022.
//

#ifndef LABA2_CALCULATION_H
#define LABA2_CALCULATION_H

#include <iostream>
#include <vector>
#include <numeric>

int calculation(std::vector <int> vec) {
    auto sum_of_elements = std::accumulate(vec.begin(), vec.end(), 0);
    return sum_of_elements;
}

#endif //LABA2_CALCULATION_H
