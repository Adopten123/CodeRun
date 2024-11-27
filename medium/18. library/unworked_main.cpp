#include <iostream>
#include <cassert>
#include <cstdint>
#include <string>
#include <vector>

int64_t find_day_count(int64_t k, int64_t m, int d) {
    int64_t count = 0;
    int64_t hungry_count = 0;

    for (int i = d; i <= 7; ++i) {
        if (i != 6 and i !=7 ) {
            m += k;
        }
        hungry_count = i - d + 1;
        m -= hungry_count;
        if (m < 0) return count;
        ++count;
    }

    uint64_t left = 0;
    uint64_t right = LONG_MAX;
    while (right - left > 1) {
        uint64_t middle = (left + right) / 2;
        if ((m + middle * k * 5) - ((middle * 7) * (2 * (hungry_count) + 1 + middle * 7) / 2) >= 0)
            left = middle;
        else
            right = middle;
    }
    m = (m + left * k * 5) - ((left * 7) * (2 * (hungry_count) + 1 + left * 7) / 2);
    hungry_count += left * 7;
    count += left * 7;
    //std::cout << count << std::endl;
    //std::cout << hungry_count << std::endl;
    for (int i = 1; i < 7; ++i) {
        if (i != 6) {
            m += k;
        }
        m -= ++hungry_count;
        //std::cout << "day "<< i <<": " <<  m << "\t" << hungry_count << std::endl;
        if (m < 0) {
            //std::cout << count << std::endl;
            break;
        }
        ++count;
    }
    return count;
}

void test() {
    assert(find_day_count(4,2,5) == 4);
    assert(find_day_count(4,3,5) == 5);
    assert(find_day_count(2, 3,1) == 4);
    assert(find_day_count(1, 10,3) == 4);
    assert(find_day_count(3, 4,5) == 4);
    assert(find_day_count(5, 0,1) == 6);
    assert(find_day_count(4, 6,6) == 6);
    assert(find_day_count(1, 0,7) == 0);
    assert(find_day_count(1000000000, 1000000000,1) == 1428571429);
    assert(find_day_count(1, 0,6) == 0);
    assert(find_day_count(2, 0,5) == 1);

}

int main()
{
    //test();
    int64_t k,m;
    int d;
    //std::cin >> k >> m >> d;
    //std::cout << find_day_count(k, m, d) << std::endl;

    std::cout << find_day_count(1000000000, 1000000000,1) << std::endl;
    //test();

    return 0;
}