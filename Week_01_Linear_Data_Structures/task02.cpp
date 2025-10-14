#include <iostream>
#include <vector>

const std::size_t N_VALUES = 1024;

unsigned int getUniqueValueCount(const int n)
{
    std::vector<bool> seen(N_VALUES, 0);
    int temp;

    for (std::size_t it = 0; it < n; ++it)
    {
        std::cin >> temp;
        seen[temp] = 1;
    }

    unsigned int count = 0;
    for (const bool val : seen)
        count += val;
    
    return count;
} 

int main()
{
    unsigned int n;
    std::cin >> n;

    std::cout << getUniqueValueCount(n) << std::endl;

    return 0;
}