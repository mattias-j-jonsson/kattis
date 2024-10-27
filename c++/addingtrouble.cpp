#include<iostream>

int main(int argc, char const *argv[])
{
    long A, B, C;
    std::cin >> A >> B >> C;

    if ((A + B) == C)
        std::cout << "correct!" << "\n";
    else
        std::cout << "wrong!" << "\n";    
    return 0;
}
