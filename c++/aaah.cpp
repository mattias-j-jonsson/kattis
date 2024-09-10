#include<iostream>

int main(int argc, char const *argv[])
{
    std::string capability, requirement;

    std::cin >> capability >> requirement;

    if(capability.length() >= requirement.length())
        std::cout << "go\n";
    else
        std::cout << "no\n";
    
    return 0;
}
