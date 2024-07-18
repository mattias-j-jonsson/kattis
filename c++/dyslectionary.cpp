#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<iomanip>



int main(int argc, char const *argv[])
{
    // std::fstream temp_stream;
    // temp_stream.open("sample.in");

    // std::string temp;
    // std::vector<std::vector<std::string>> word_lists{std::vector<std::string>()};
    // std::vector<int> widths;
    // int max_width = 0;
    // while (std::getline(temp_stream, temp)) 
    // {
    //     if (temp == "")
    //     {
    //         widths.push_back(max_width);
    //         max_width = 0;
    //         word_lists.push_back(std::vector<std::string>());
    //     }
    //     else
    //     {
    //         word_lists.back().push_back(temp);
    //         if (temp.length() > max_width)
    //             max_width = temp.length();
    //     }   
    // }
    // widths.push_back(max_width);

    std::string temp;
    std::vector<std::vector<std::string>> word_lists{std::vector<std::string>()};
    std::vector<int> widths;
    int max_width = 0;
    while (std::getline(std::cin, temp)) 
    {
        if (temp == "")
        {
            widths.push_back(max_width);
            max_width = 0;
            word_lists.push_back(std::vector<std::string>());
        }
        else
        {
            word_lists.back().push_back(temp);
            if (temp.length() > max_width)
                max_width = temp.length();
        }   
    }
    widths.push_back(max_width);
    
    
    for(auto& v : word_lists)
    {
        for(std::string& s : v)
            std::reverse(s.begin(), s.end());
        std::sort(v.begin(), v.end());
        for(std::string& s : v)
            std::reverse(s.begin(), s.end());
    }

    for (int i = 0; i < word_lists.size(); i++)
    {
        for(auto& s : word_lists[i])
            std::cout << std::right << std::setw(widths[i]) << s << std::endl;
        if(i != word_lists.size()-1)
            std::cout << std::endl;
    }
    

    return 0;
}
