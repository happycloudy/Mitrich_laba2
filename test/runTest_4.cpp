#include "../src/parallelStarter.h"
#include <vector>
#include <cassert>

int main() {
    std::vector<std::vector<int>> vec;
    int num_of_vectors = 5;
    int vec_size = 1000000;
    for (int i = 0; i < num_of_vectors; i++){
        std::vector<int> generated_vec = {};
        for (int j = 0; j < vec_size; j++){
            int el = (j % 2?-1:1);
            generated_vec.push_back(el);
        }
        vec.push_back(generated_vec);
    }
    std::vector<int>res = parallelStarter(4, vec);
    int res_sum = 0;
    for (int i = 0; i < num_of_vectors; i++) {
        res_sum += res[i];
    }
    assert(res_sum == 0);
    return 0;
}