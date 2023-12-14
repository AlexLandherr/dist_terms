#include <string>

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

namespace func {
    std::string add_num_str(std::string &str1, std::string &str2);
    std::string multiply_num_str(std::string &str1, std::string &str2);
    std::string power_of_str(std::string &base, int exponent);
    int distinct_term_count(int lower_limit_a, int upper_limit_a, int lower_limit_b, int upper_limit_b);
}

#endif