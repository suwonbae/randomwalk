#include "tools.h"

// helper function
long double next_rand_val(std::mt19937& gen) {
    std::uniform_real_distribution<long double> uni(0, 1);
    return uni(gen);
}

