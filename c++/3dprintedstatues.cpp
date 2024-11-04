#include <iostream>
#include <algorithm>
#include <cmath>

int main(int argc, char const *argv[])
{
    int target;
    std::cin >> target;
    int days = ceil(log2(target));
    days++;
    std::cout << days << "\n";
    
    return 0;
}