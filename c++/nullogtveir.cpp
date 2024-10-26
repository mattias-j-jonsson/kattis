#include <iostream>
#include <cmath>

int main(int argc, char const *argv[])
{
    std::string num_str;
    std::cin >> num_str;
    int num_length = num_str.length();
    long long result = std::exp2(num_length);

    for (int i = 0; i < num_length; i++)
    {
        int current_digit = num_str[i] - '0';
        if (current_digit >= 3)
            break;
        else if(current_digit == 2)
            continue;
        else if (current_digit == 1)
        {
            result -= std::exp2(num_length - i - 1);
            break;
        }
        else if (current_digit == 0)
        {
            result -= std::exp2(num_length - i - 1);
            continue;
        }
    }

    std::cout << result << "\n";
    return 0;
}


/*
    9999 = 2222 2220 2202 2200 2022 2020 2002 2000, 222 220 202 200, 22 20 2 0: 16 = 2^4
    9199 = 16 st
    2222 = 16 st
    2221 = 15 = 16 - 2^0 = 2220
    2219 = 14 = 16 - 2^1 = 2210 = 2202
    2199 = 12 = 16 - 2^2 = 2022
    2021 = 11 = 16 - 2^2 - 2^0 = 2020
    2019 = 10 = 16 - 2^2 - 2^1 = 2002
    2001 = 9 = 16 - 2^2 - 2^1 - 2^0 = 2000
    1999 = 8 st = 16 - 2^3 = 222
    222 = 8 st
    221 = 7 = 8 - 2^0 = 220
    219 = 6 = 8 - 2^1 = 202
    201 = 5 = 8 - 2^1 - 2^0 = 200
    199 = 4 = 8 - 2^2 = 22
 */