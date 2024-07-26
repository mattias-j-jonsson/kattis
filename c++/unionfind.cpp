#include<iostream>

int find_set(int a, int* set_vector)
{
    if (set_vector[a] == a)
    {
        return a;
    }
    
    set_vector[a] = find_set(set_vector[a], set_vector);
    return set_vector[a];
}

void unionize(int a, int b, int* set_vector, int* size_vector)
{
    a = find_set(a, set_vector);
    b = find_set(b, set_vector);

    if (size_vector[a] < size_vector[b])
    {
        set_vector[a] = set_vector[b];
        size_vector[b] += size_vector[a];
    } else
    {
        set_vector[b] = set_vector[a];
        size_vector[a] += size_vector[b];
    }   
}

int main(int argc, char const *argv[])
{
    // kattis-specifika saker
    // ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    //
    
    
    int N, Q;
    std::cin >> N >> Q;

    int set_vector[N];
    int size_vector[N];

    for (int i = 0; i < N; i++)
    {
        set_vector[i] = i;
        size_vector[i] = 1;
    }

    char command;
    int a,b;
    for (int i = 0; i < Q; i++)
    {
        std::cin >> command >> a >> b;
        
        if (command == '=')
        {
            unionize(a, b, set_vector, size_vector);
        } else
        {
            if (find_set(a, set_vector) == find_set(b, set_vector))
            {
                std::cout << "yes\n";
            } else 
            {
                std::cout << "no\n";
            }
        }
        
    }

    return 0;
}
