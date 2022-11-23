//
// Created by Artur1337 on 23.11.2022.
//

#ifndef LABA2_PARALLELSTARTER_H
#define LABA2_PARALLELSTARTER_H

#include <iostream>
#include <vector>
#include <omp.h>
#include <ctime>
#include "calculation.h"
#include "genVectors.h"

std::vector<int> parallelStarter(int treads, const std::vector<std::vector<int>>& parentVector) {
    const int num_of_vectors = 8;
    std::vector<int> sumVector;
    omp_set_num_threads(treads);

    #pragma omp parallel for default(none) shared(num_of_vectors, parentVector, std::cout, sumVector)
        for (const auto& vecItem: parentVector) {
            auto sum = calculation(vecItem);
            sumVector.push_back(sum);
    #pragma omp critical
            std::cout << sum << std::endl;
        }

    return sumVector;
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

#endif //LABA2_PARALLELSTARTER_H
