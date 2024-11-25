#include <iostream>
#include <cmath>
#include <cstdint>
#include <string>
#include <set>
#include <vector>

int find_count(uint64_t  a, uint64_t  b) {
    uint64_t quotient = b / a;

    const uint64_t lim = std::sqrt(quotient)+1;
    int count = 0;

    for(int i = 2; i <= lim; i++) {
        if(quotient % i == 0) {
            ++count;
        }
        while(quotient % i == 0) quotient /= i;
    }
    if(quotient > 1) ++count;

    return std::pow(2, count);
}


int main()
{
    uint64_t  x, y;
    std::cin >> x >> y;
    if(y % x != 0) {
        std::cout << 0 << std::endl;
    }
    else {
        std::cout << find_count(x, y) << std::endl;
    }

    return 0;
}