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
    int sum_of_elements = 0;
    sum_of_elements = std::accumulate(vec.begin(), vec.end(), 0);
    std::cout << sum_of_elements << std::endl;
    return sum_of_elements;
}

void parallelStarter() {
    const unsigned vec_size = 10000000;
    std::vector <int> vec(vec_size);
    std::generate(vec.begin(), vec.end(), genNumbers);
    calculation(vec);
}





#endif //LABA2_UTILS_H