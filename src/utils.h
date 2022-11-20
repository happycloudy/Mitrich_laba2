//
// Created by Artur1337 on 17.11.2022.
//
#ifndef LABA2_UTILS_H
#define LABA2_UTILS_H

#include <random>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <numeric>

double genNumbers() {
    static std::mt19937 gen(time(nullptr));
    std::uniform_int_distribution<> dist(-100, 100);
    return dist(gen);
}

int calculation(std::vector <int> vec) {
    auto sum_of_elements = std::accumulate(vec.begin(), vec.end(), 0);
    return sum_of_elements;
}

void parallelStarter() {
    const unsigned vec_size = 1000;
    const int num_of_vectors = 8;
    std::vector<std::vector<int> > vec;
    std::generate_n(std::back_inserter(vec), num_of_vectors,
    [num_of_vectors]() -> std::vector<int>
    {
        std::vector<int> myVec;
        std::generate_n(std::back_inserter(myVec), vec_size, []() { return genNumbers(); });
        return myVec;
    });

    std::for_each(vec.begin(), vec.end(), [](std::vector<int> iVec) {
        auto sum = calculation(iVec);
        std::cout << sum << std::endl;
    });

}

#endif //LABA2_UTILS_H