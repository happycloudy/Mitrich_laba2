#include "../src/genVectors.h"
#include "../src/calculation.h"

#include <cassert>

int main() {

    const int num_of_vectors = 16;
    const unsigned vec_size = 10000000;
    auto vec = genVector(num_of_vectors, vec_size);

    #pragma omp parallel for default(none) shared(num_of_vectors, vec)
    for (const auto& vecItem: vec) {
        auto sum = 0;
        auto calc_sum = calculation(vecItem);
        for (int i = 0; i < vec_size; i++){
            sum += vecItem[i];
        }
        assert(sum == calc_sum);
    }
    return 0;
}