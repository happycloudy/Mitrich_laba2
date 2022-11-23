//
// Created by Artur1337 on 23.11.2022.
//

#ifndef LABA2_CALCULATION_H
#define LABA2_CALCULATION_H

#include <iostream>
#include <vector>
#include <numeric>

int calculation(const std::vector <int>& vec) {

    int sum_of_elements = 0;

    for (auto& vecItem: vec) {
        sum_of_elements += vecItem;
    }

    return sum_of_elements;
}

#endif //LABA2_CALCULATION_H
