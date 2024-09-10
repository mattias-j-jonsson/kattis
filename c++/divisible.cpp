#include<iostream>

int main(int argc, char const *argv[])
{
    // freopen("sample.in", "r", stdin); // debug

    // // Kattis I/O-grejjer
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    // //////////////////////////


    int nr_tc;
    std::cin >> nr_tc;

    while (nr_tc)
    {
        int divisor, sequence_length;
        std::cin >> divisor >> sequence_length;
        int mod_frequencies[divisor];
        for (int i = 0; i < divisor; i++)
        {
            mod_frequencies[i] = 0;
        }
        
        int count = 0;
        int current;
        int sum = 0, mod;
        mod_frequencies[0] = 1;
        for(int i = 0; i < sequence_length; i++)
        {
            std::cin >> current;
            sum = (sum + current % divisor) % divisor;
            // mod = sum % divisor;
            if (mod_frequencies[sum] != 0)
            {
                count += mod_frequencies[sum];
                mod_frequencies[sum]++;
            } else
            {
                mod_frequencies[sum] = 1;   
            }
        }
        std::cout << count << "\n";

        nr_tc--;
    }
    
    

    return 0;
}
