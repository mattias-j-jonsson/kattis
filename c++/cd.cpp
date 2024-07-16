#include<iostream>
#include<fstream>
#include<cstddef>

int main(int argc, char const *argv[])
{
    // std::fstream temp_stream;
    // temp_stream.open("A.0.in");
    // if (temp_stream.is_open() == false)
    // {
    //     std::cout << "Could not open file." << std::endl;
    //     return 1;
    // }
    
    int jacks_size;
    int jills_size;
    std::cin >> jacks_size >> jills_size; 
    while (jacks_size != 0 && jills_size != 0)
    {
        long inventory[1000000] = {};
        
        long temp_long;
        for (size_t i = 0; i < jacks_size; i++)
        {
            std::cin >> temp_long;
            inventory[i] = temp_long;
        }

        int index_in_jacks_collection = 0, no_of_doubles = 0;
        long current_long;
        for (size_t i = 0; i < jills_size; i++)
        {
            std::cin >> current_long;
            while (current_long > inventory[index_in_jacks_collection] && inventory[index_in_jacks_collection] != 0)
            {
                index_in_jacks_collection++;
            }
            if (current_long == inventory[index_in_jacks_collection])
            {
                no_of_doubles++;
            }
        }
        
        // for (size_t i = 0; i < jills_size; i++)
        // {
        //     std::cin >> current_long;
        //     for (size_t j = 0; j < jacks_size; j++)
        //     {
        //         if (current_long == inventory[j])
        //         {
        //             no_of_doubles++;
        //         }
                
        //     }
            
        // }
        

        std::cout << no_of_doubles << std::endl;

        std::cin >> jacks_size >> jills_size;
    }
    return 0;
}
