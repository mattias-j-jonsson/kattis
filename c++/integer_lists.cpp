#include<iostream>
#include<fstream>
#include<vector>
#include<cstdio>

int main(int argc, char const *argv[])
{
    // freopen("I.in", "r", stdin); //debug

    // Kattis I/O-grejjer
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    //////////////////////////

    int no_test_cases;
    std::cin >> no_test_cases;
    for (int i = 0; i < no_test_cases; i++)
    {
        std::string command;
        int input_size;
        std::cin >> command >> input_size;
        std::vector<int> input_normal;
        input_normal.reserve(input_size);
        std::cin.get(); //getchar(); // newline
        std::cin.get(); //getchar(); // vänster-bracket
        for (int j = 0; j < input_size; j++)
        {
            int temp;
            std::cin >> temp;
            std::cin.get(); //getchar(); // komma samt höger-bracket
            input_normal.emplace_back(temp);
        }
        std::cin.get(); //getchar(); // newline

        bool error = false, reverse = false;
        int R_count = 0;
        for (char c : command)
        {
            if (c == 'R')
            {
                R_count++;
            } else
            {
                if (input_normal.size() == 0)
                {
                    error = true;
                    break;
                }
                else if(R_count % 2 == 0)
                {
                    input_normal.erase(input_normal.begin());
                    reverse = false;
                }
                else
                {
                    input_normal.erase(input_normal.end()-1);
                    reverse = true;
                }
                // R_count = 0;
            }
        }
        if(R_count % 2 == 1)
            reverse = true;
        else
            reverse = false;
        
        // result
        if(error)
            std::cout << "error\n";
        else if(input_normal.size() == 0)
        {
            std::cout << "[]\n";
        }
        else if (reverse)
        {
            std::cout << "[";
            for (int j = input_normal.size()-1; j >=1; j--)
            {
                std::cout << input_normal[j] << ",";
            }
            std::cout << input_normal[0] << "]\n";
        } else
        {
            std::cout << "[";
            for (int j = 0; j < input_normal.size()-1; j++)
            {
                std::cout << input_normal[j] << ",";
            }
            std::cout << input_normal[input_normal.size()-1] << "]\n";
        }
    }
        
    
    return 0;
}
