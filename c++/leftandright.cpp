#include<iostream>
#include<vector>

int main(int argc, char const *argv[])
{
    int n;
    std::cin >> n;
    std::string directions;
    std::cin >> directions;

    int L_count = 0;
    int current_pos = 0;
    std::vector<int> path;
    path.reserve(n);
    for (int i = 0; i < directions.size(); i++)
    {
        if (directions[i] == 'R')
        {
            current_pos++;
            path.push_back(current_pos);
            int temp_pos = current_pos;
            while (L_count)
            {
                path.push_back(--temp_pos);
                L_count--;
            }
        } else
        {
            L_count++;
            current_pos++;
        }
    }

    if(L_count)
    {
        current_pos++;
        path.push_back(current_pos);
        while (L_count)
        {
            path.push_back(--current_pos);
            L_count--;
        }
        
    } else
    {
        for (int i = current_pos; i < n; i++)
        {
            current_pos++;
            path.push_back(current_pos);
        }
    }


    for(int& p : path)
    {
        std::cout << p << "\n";
    }

    return 0;
}
