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
#include <omp.h>
#include <ctime>

double genNumbers() {
    static std::mt19937 gen(time(nullptr));
    std::uniform_int_distribution<> dist(-100, 100);
    return dist(gen);
}

int calculation(std::vector <int> vec) {
    auto sum_of_elements = std::accumulate(vec.begin(), vec.end(), 0);
    return sum_of_elements;
}

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

void parallelStarter(int treads, const std::vector<std::vector<int>>& parentVector) {
    const int num_of_vectors = 8;
    omp_set_num_threads(treads);

    unsigned int start_time =  clock();

    #pragma omp parallel for default(none) shared(num_of_vectors, parentVector, std::cout)
    for (const auto& vecItem: parentVector) {
        auto sum = calculation(vecItem);
        #pragma omp critical
        std::cout << sum << std::endl;
    }

    unsigned int end_time = clock();
    std::cout << "Runtime - " << (end_time - start_time) / 1000.0 << std::endl;
}

void parallelStarter(int treads) {
    const int num_of_vectors = 8;
    const unsigned vec_size = 10000000;
    omp_set_num_threads(treads);
    auto vec = genVector(num_of_vectors, vec_size);
    unsigned int start_time =  clock();

    #pragma omp parallel for default(none) shared(num_of_vectors, vec, std::cout)
        for (const auto& vecItem: vec) {
            auto sum = calculation(vecItem);
    #pragma omp critical
            std::cout << sum << std::endl;
        }

    unsigned int end_time = clock();
    std::cout << "Runtime - " << (end_time - start_time) / 1000.0 << std::endl;
}

#endif //LABA2_UTILS_H