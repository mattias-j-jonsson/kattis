#include<iostream>
#include<fstream>


int main(int argc, char const *argv[])
{
    
    // std::fstream input_stream;
    // input_stream.open(argv[1]);
    

    // std::string input_str;
    // std::getline(input_stream, input_str);
    // input_stream.close();

    std::string input_str;
    getline(std::cin, input_str);
    

    int l_count = 0, r_count = 0;
    bool eyefound = false;
    for(char c : input_str)
    {
        if(c == '(')
        {
            eyefound = true;
            continue;
        }
        if(eyefound == false)
        {
            l_count++;
        }
        if(c == ')')
        {
            continue;
        }
        if(eyefound)
        {
            r_count++;
        }
    }

    if (l_count == r_count)
    {
        std::cout << "correct";
    }
    else
    {
        std::cout << "fix";
    }
    
    
    return 0;
}
