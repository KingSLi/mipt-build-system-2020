#include "main.h"
#include <iostream>

int main() {
    int len = sizeof(powers)/sizeof(powers[0]);
    for (int i = 0; i < len; ++i)
        std::cout << powers[i] << ": " << binpow(2, powers[i]) << std::endl;
}