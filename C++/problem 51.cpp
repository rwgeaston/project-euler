#include <iostream>
#include <math.h>

int primes_length = 100000;

int* get_composite_numbers() {
    int* composites = new int[primes_length];
    // We have to label anythnig divisible by 2 as composite by setting it to 1
    // And then label anything divisible by any other prime similarly
    // When we've done every factor upto sqrt length of the array,
    // we know we've found all composites
    for (int factor = 2; factor <= sqrt(primes_length) + 1; factor++) {
        if (!composites[factor]) {
            for (
                int composite = factor * 2;
                composite < primes_length;
                composite += factor
            ) {
                composites[composite] = 1;
            }
        }
    }
    return composites;
}

void print_array(int* array, int length) {
    for (int i = 0; i < length - 1; i++) {
        std::cout << array[i] << ',';
        if (i % 20 == 19) {
            std::cout << std::endl;
        }
    }
    std::cout << array[length - 1];
}

int fill_template(
    int* family_template,
    int family_template_length,
    int wildcard
) {
    int test_value = 0;

    for (int digit = 0; digit < family_template_length; digit++) {
        // Pointless but harmless on the first loop.
        // After that it lets us move onto the next digit.
        test_value *= 10;
        if (family_template[digit] == 11) {
            test_value += wildcard;
        } else {
            test_value += family_template[digit];
        }
    }

    return test_value;
}

int count_primes_in_template(
    int* composites,
    int* family_template,
    int family_template_length,
    bool debug
) {
    int prime_count = 0;
    for (int wildcard = 0; wildcard <= 9; wildcard++) {
        int test_value = fill_template(
            family_template,
            family_template_length,
            wildcard
        );
        if (!composites[test_value]) {
            prime_count++;
            if (debug) {
                std::cout << test_value << " is prime." << std::endl;
            } else if(debug) {
                std::cout << test_value << " is composite." << std::endl;
            }
        }
    }
    return prime_count;
}

void print_template_and_prime_count(
    int* family_template,
    int length,
    int prime_count
) {
    for (int i = 0; i < length; i++) {
        if (family_template[i] == 11) {
            std::cout << '*';
        } else {
            std::cout << family_template[i];
        }
    }
    std::cout << " has " << prime_count
              << " prime(s) in its family." << std::endl;
}

int main() {
    int* composites = get_composite_numbers();

    // Need to generate all templates
    // Use 11 for a blank and single digit numbers for themselves
    // For now let's use one template
    int family_template_length = 2;
    int family_template[family_template_length];
    for (int digit = 0; digit < family_template_length; digit++) {
    {5, 6, 11, 11, 3};
    
    // How many primes match this template?
    int prime_count = count_primes_in_template(
        composites,
        family_template,
        family_template_length,
        false
    );
    print_template_and_prime_count(
        family_template,
        family_template_length,
        prime_count
    );

}