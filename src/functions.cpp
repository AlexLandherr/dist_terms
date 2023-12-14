#include "include/functions.h"
#include <string>
#include <vector>
#include <algorithm>
#include <cstdint>

namespace func {
    //Add two positive integers represented as strings and get the sum as a string.
    std::string add_num_str(std::string &str1, std::string &str2) {
        std::string result;
        //Making sure number strings are equally long.
        if (str1.length() > str2.length()) {
            str2.insert(0, (str1.length() - str2.length()), '0');
        } else if (str2.length() > str1.length()) {
            str1.insert(0, (str2.length() - str1.length()), '0');
        }

        //Adding number strings together, one digit at a time from right to left.
        int carry = 0;
        for (int i = static_cast<int>(str1.length()) - 1; i >= 0; i--) {
            result.insert(0, std::to_string(((str1[i] - 48) + (str2[i] - 48) + carry) % 10));
            carry = ((str1[i] - 48) + (str2[i] - 48) + carry) / 10;
        }

        //Prepend the final carry value to the result std::string.
        if (carry > 0) {
            result.insert(0, std::to_string(carry));
        }

        return result;
    }

    //Multiply two positive integers represented as strings and get product as a string.
    std::string multiply_num_str(std::string &str1, std::string &str2) {
        /*For each digit in str1 multiply it with each digit from str2 (from right to left)
        and add the carry to said product.
            
        Then prepend the (result % 10) to a string to be inserted in a vector holding the result for
        the each digit in str1 times the corresponding one in str2.
            
        Then take the sum of the numbers in the vector to get the final product.*/
        std::string result = "0";
        std::vector<std::string> interim_results;

        if (str1.length() > str2.length()) {
            for (int i = static_cast<int>(str2.length()) - 1; i >= 0; i--) {
                uint64_t carry = 0;
                std::string current_digit_prod_str;

                for (int j = static_cast<int>(str1.length()) - 1; j >= 0; j--) {
                    current_digit_prod_str.insert(0, std::to_string((((str2[i] - 48) * (str1[j] - 48)) + carry) % 10));

                    carry = (((str2[i] - 48) * (str1[j] - 48)) + carry) / 10;
                }

                if (carry > 0) {
                    current_digit_prod_str.insert(0, std::to_string(carry));
                }

                interim_results.push_back(current_digit_prod_str);
            }
            
            //Appending zeros to the end of all interrim results to make their summation be correct.
            for (int n = 0; n < static_cast<int>(interim_results.size()); n++) {
                if (n == 0) {
                    continue;
                } else {
                    interim_results[n] = interim_results[n].append(n, '0');
                }
            }

            if (interim_results.size() == 1) {
                result = interim_results[0];
            } else {
                for (int k = 0; k < static_cast<int>(interim_results.size()); k++) {
                    result = add_num_str(result, interim_results[k]);
                }
            }
            
            //Remove leading zeros.
            result.erase(0, std::min(result.find_first_not_of('0'), result.size() - 1));

            return result;
        } else if (str1.length() < str2.length()) {
            for (int i = static_cast<int>(str1.length()) - 1; i >= 0; i--) {
                uint64_t carry = 0;
                std::string current_digit_prod_str;

                for (int j = static_cast<int>(str2.length()) - 1; j >= 0; j--) {
                    current_digit_prod_str.insert(0, std::to_string((((str1[i] - 48) * (str2[j] - 48)) + carry) % 10));

                    carry = (((str1[i] - 48) * (str2[j] - 48)) + carry) / 10;
                }

                if (carry > 0) {
                    current_digit_prod_str.insert(0, std::to_string(carry));
                }

                interim_results.push_back(current_digit_prod_str);
            }
            
            //Appending zeros to the end of all interrim results to make their summation be correct.
            for (int n = 0; n < static_cast<int>(interim_results.size()); n++) {
                if (n == 0) {
                    continue;
                } else {
                    interim_results[n] = interim_results[n].append(n, '0');
                }
            }

            if (interim_results.size() == 1) {
                result = interim_results[0];
            } else {
                for (int k = 0; k < static_cast<int>(interim_results.size()); k++) {
                    result = add_num_str(result, interim_results[k]);
                }
            }
            
            //Remove leading zeros.
            result.erase(0, std::min(result.find_first_not_of('0'), result.size() - 1));

            return result;
        } else {
            for (int i = static_cast<int>(str1.length()) - 1; i >= 0; i--) {
                uint64_t carry = 0;
                std::string current_digit_prod_str;

                for (int j = static_cast<int>(str2.length()) - 1; j >= 0; j--) {
                    current_digit_prod_str.insert(0, std::to_string((((str1[i] - 48) * (str2[j] - 48)) + carry) % 10));

                    carry = (((str1[i] - 48) * (str2[j] - 48)) + carry) / 10;
                }

                if (carry > 0) {
                    current_digit_prod_str.insert(0, std::to_string(carry));
                }

                interim_results.push_back(current_digit_prod_str);
            }
            
            //Appending zeros to the end of all interrim results to make their summation be correct.
            for (int n = 0; n < static_cast<int>(interim_results.size()); n++) {
                if (n == 0) {
                    continue;
                } else {
                    interim_results[n] = interim_results[n].append(n, '0');
                }
            }

            if (interim_results.size() == 1) {
                result = interim_results[0];
            } else {
                for (int k = 0; k < static_cast<int>(interim_results.size()); k++) {
                    result = add_num_str(result, interim_results[k]);
                }
            }
            
            //Remove leading zeros.
            result.erase(0, std::min(result.find_first_not_of('0'), result.size() - 1));

            return result;
        }
    }

    std::string power_of_str(std::string &base, int exponent) {
        /* std::string result = "1";
        for (int i = 0; i < exponent; i++) {
            result = multiply_num_str(result, base);
        }
        return result; */
        if (exponent == 0) {
            return "1";
        } else if (exponent == 1) {
            return base;
        } else {
            std::vector<std::string> all_powers = {multiply_num_str(base, base)};
            for (int i = 3; i <= exponent; i++) {
                std::string temp_res = multiply_num_str(all_powers.back(), base);
                all_powers.push_back(temp_res);
            }
            return all_powers.back();
        }
    }

    int distinct_term_count(int lower_limit_a, int upper_limit_a, int lower_limit_b, int upper_limit_b) {
        std::vector<std::string> term_vector;

        for (int a = lower_limit_a; a <= upper_limit_a; a++) {
            std::string base = std::to_string(a);
            for (int b = lower_limit_b; b <= upper_limit_b; b++) {
                std::string temp_candidate = power_of_str(base, b);
                if (std::find(term_vector.begin(), term_vector.end(), temp_candidate) != std::end(term_vector)) {
                    continue;
                } else {
                    term_vector.push_back(temp_candidate);
                }
            }
        }

        return static_cast<int>(term_vector.size());
    }
}