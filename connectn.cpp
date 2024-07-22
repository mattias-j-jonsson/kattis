#include<fstream>
#include<iostream>
#include<vector>

struct Result
{
    bool result;
    char winner;
    Result(bool r, char w) : result(r), winner(w) {}
};


Result check_rows_or_columns(std::vector<std::vector<char>>& vec, int N)
{
    for(auto& v : vec)
    {
        int sum = 0;
        char current_winner = 'X';
        for(int i = 0; i < v.size(); i++)
        {
            if (v[i] == current_winner)
            {
                sum++;
                if (sum == N)
                    return {true, current_winner};
            } else
            {
                sum = 0;
                if(v[i] == 'B' || v[i] == 'R')
                {
                    sum++;
                    current_winner = v[i];
                }
            }
        }
    }
    
    
    return {false, '0'};
}

Result check_diagonal(std::vector<std::vector<char>>& rows, int N)
{
    std::vector<std::vector<char>> diagonals;

    int row_length = rows[0].size();
    int column_length = rows.size();

    
    for(int i = 0; i < row_length; i++)
    {
        std::vector<char> d;
        for(int j = 0; j < column_length; j++)
        {
            if(j+i < row_length)
                d.push_back(rows[j][j+i]);
                // std::cout << "[" << j << "][" << j+i << "]\n";
        }
        // std::cout << std::endl;
        if (d.size() >= N)
            diagonals.push_back(d);
    }
    // 00 11 22, 01 12 23, 02 13 24, 03 14 25

    for(int i = 1; i < column_length; i++)
    {
        std::vector<char> d;
        for(int j=0; j < column_length; j++)
        {
            if(i+j<column_length)
                d.push_back(rows[i+j][j]);
                // std::cout << "[" << i+j << "][" << j << "]\n";
        }
        if (d.size() >= N)
            diagonals.push_back(d);
        // std::cout << std::endl;
    }
    // 10 21, 20

    for(int i = 0; i < row_length; i++)
    {
        std::vector<char> d;
        for(int j = column_length-1; j >= 0; j--)
        {
            if ((column_length-1-j)+i < row_length)
                d.push_back(rows[j][column_length-1-j+i]);
                // std::cout << "[" << j << "][" << (column_length-1-j) + i << "]\n";
        }
        if(d.size() >= N)
            diagonals.push_back(d);
        // std::cout << "\n";
    }
    // 20 11 02, 21 12 03, 22 13 04, 23 14 05

    for(int i = column_length-2; i >= 0; i--)
    {
        std::vector<char> d;
        for(int j = 0; j < column_length; j++)
        {
            if(i-j >= 0)
                d.push_back(rows[i-j][j]);
                // std::cout << "[" << i-j << "][" << j << "]\n";
        }
        if(d.size() >= N)
            diagonals.push_back(d);
        // std::cout << std::endl;
    }
    // 10 01, 00
    

    return check_rows_or_columns(diagonals, N);
}



int main(int argc, char const *argv[])
{
    // std::fstream temp_stream("connectn-003.in");

    // int X,Y,N;
    // temp_stream >> X >> Y >> N;
    // std::vector<std::vector<char>> rows(X), columns(Y);
    // for (int i = 0; i < X; i++)
    // {
    //     for(int j = 0; j < Y; j++)
    //     {
    //         char temp;
    //         temp_stream >> temp;
    //         rows[i].push_back(temp);
    //         columns[j].push_back(temp);
    //     }
    // }

    int X,Y,N;
    std::cin >> X >> Y >> N;
    std::vector<std::vector<char>> rows(X), columns(Y);
    for (int i = 0; i < X; i++)
    {
        for(int j = 0; j < Y; j++)
        {
            char temp;
            std::cin >> temp;
            rows[i].push_back(temp);
            columns[j].push_back(temp);
        }
    }



    Result final_result(false, '0');
    Result temp_result = check_rows_or_columns(rows, N);
    if(temp_result.result)
        final_result = temp_result;
    else
    {
        temp_result = check_rows_or_columns(columns, N);
        if (temp_result.result)
            final_result = temp_result;
        else
        {
            final_result = check_diagonal(rows, N);
        }
    }

    if(final_result.result)
        if(final_result.winner == 'B')
            std::cout << "BLUE WINS\n";
        else
            std::cout << "RED WINS\n";
    else
        std::cout << "NONE\n";
    
    return 0;
}
