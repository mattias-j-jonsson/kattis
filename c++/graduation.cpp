#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    // freopen("4.in", "r", stdin); // debug
    
    int N, M, K;
    std::cin >> N >> M >> K;

    std::string lines[N];
    for(int i = 0; i < N; i++)
    {
        std::cin >> lines[i];
    }

    std::vector<std::string> colors(K);
    
    for(int i = 0; i < M; i++)
    {
        int current_color = 0;
        int column_color = K - 1;
        std::string column = "";
        
        for(int j = 0; j < N; j++)
        {
            current_color = 0;
            char current_char = lines[j][i];
            
            while(colors[current_color].find_first_of(current_char) == std::string::npos && colors[current_color].size() != 0)
            {
                current_color++;
            }
            
            if (current_color < column_color)
                column_color = current_color;

            if(column.find_first_of(current_char) == std::string::npos)
                column += current_char;
        }
        for (int j = 0; j < column.length(); j++)
        {
            if (colors[column_color].find_first_of(column[j]) == std::string::npos)
                colors[column_color] += column[j];
        }
    }

    int result = 0;
    
    for (int i = 0; i < K; i++)
    {
        if(colors[i].length() != 0)
            result++;
        else
            break;
    }
    

    std::cout << result << "\n";
    
    
    return 0;
}
