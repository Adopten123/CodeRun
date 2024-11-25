#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main()
{
    int len;
    cin >> len;

    std::vector<int> arr(len);
    for (size_t i = 0; i < len; ++i) {
        std::cin >> arr[i];
    }

    map<int, int> dic;
    for (int i = 0; i < len; ++i) {
        dic[arr[i]]++;
    }

    int c = 0;
    for (const auto& [key, value] : dic) {
        c += value == 1 ? 1 : 0;
    }

    cout << c << endl;

    return 0;
}