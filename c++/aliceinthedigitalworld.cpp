#include<iostream>
#include<fstream>
#include<vector>


int solution(std::vector<unsigned int>& current_set, std::vector<unsigned int>& m_positions, int m)
{
    int current_solution = 0;
    
    int range_start, range_end;
    int practical_start, practical_end;
    int current_mPos;
    for(int j = 0; j < m_positions.size(); j++)
    {
        if (j == 0)
        {
            range_start = 0;
            if (m_positions.size() > 1)
                range_end = m_positions[1];
            else
                range_end = current_set.size();
        } else if (j == m_positions.size()-1)
        {
            range_start = m_positions[j-1]+1;
            range_end = current_set.size();
        } else
        {
            range_start = m_positions[j-1]+1;
            range_end = m_positions[j+1];
        }
        current_mPos = m_positions[j];
        practical_start = range_start;
        practical_end = range_end;

        for(int i = range_start; i < range_end; i++)
        {
            if (current_set[i] < m && i < current_mPos)
                practical_start = i+1;
            else if (current_set[i] < m && i > current_mPos)
            {
                practical_end = i;
                break;
            }
        }
        int temp_solution = 0;
        if (practical_start == practical_end)
            temp_solution = m;
        else
        {
            for(int i = practical_start; i < practical_end; i++)
            {
                temp_solution += current_set[i];
            }
        }

        if (temp_solution > current_solution)
            current_solution = temp_solution;
    }

    return current_solution;
}

int main(int argc, char const *argv[])
{
    int no_sets;
    std::cin >> no_sets;
    while (no_sets > 0)
    {
        int n,m;
        std::cin >> n >> m;
        std::vector<unsigned int> m_positions;
        std::vector<unsigned int> current_set;
        current_set.reserve(n);
        for(int i = 0; i < n; i++)
        {
            int temp;
            std::cin >> temp;
            current_set.push_back(temp);
            if(temp == m)
                m_positions.push_back(i);
        }
        std::cout << solution(current_set, m_positions, m) << std::endl;

        no_sets--;
    }

    // std::fstream temp_stream;
    // temp_stream.open("sample.in");

    // int no_sets;
    // temp_stream >> no_sets;
    // while (no_sets > 0)
    // {
    //     int n,m;
    //     temp_stream >> n >> m;
    //     std::vector<unsigned int> m_positions;
    //     std::vector<unsigned int> current_set;
    //     current_set.reserve(n);
    //     for(int i = 0; i < n; i++)
    //     {
    //         int temp;
    //         temp_stream >> temp;
    //         current_set.push_back(temp);
    //         if(temp == m)
    //             m_positions.push_back(i);
    //     }
    //     std::cout << solution(current_set, m_positions, m) << std::endl;

    //     no_sets--;
    // }
    
    
    return 0;
}
