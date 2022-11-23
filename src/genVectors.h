//
// Created by Artur1337 on 23.11.2022.
//

#ifndef LABA2_GENVECTORS_H
#define LABA2_GENVECTORS_H

#include "iostream"
#include "vector"
#include "algorithm"
#include "genNumbers.h"

std::vector<std::vector<int>> genVector(int num_of_vectors, unsigned vec_size) {
    std::vector<std::vector<int>> vec;
    std::generate_n(std::back_inserter(vec), num_of_vectors, [num_of_vectors, vec_size]() -> std::vector<int>
    {
        std::vector<int> myVec;
        std::generate_n(std::back_inserter(myVec), vec_size, []() { return genNumbers(); });
        return myVec;
    });
    return vec;
}

#endif //LABA2_GENVECTORS_H
