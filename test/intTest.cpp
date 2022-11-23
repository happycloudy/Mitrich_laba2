#include "../src/genVectors.h"
#include <typeinfo>
#include <cassert>


int main() {
    const int num_of_vectors = 16;
    const unsigned vec_size = 10000000;
    auto vec = genVector(num_of_vectors, vec_size);
    #pragma omp parallel for default(none) shared(num_of_vectors, vec)
    for (const auto& vecItem: vec) {
        for (const auto& vecEl:vecItem){
            assert( typeid(vecEl).name() == typeid(1).name());
        }
    }
    return 0;
}