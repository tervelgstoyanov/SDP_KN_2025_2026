#include <iostream>
#include "PriorityQueue.hpp"

template <class T>
void heapSort(vector<T>& arr)
{
    PriorityQueue<T> p(arr);

	for (int i = arr.size() - 1; i >= 0; i--)
	{
		arr[i] = p.top();
		p.pop();
	}
}

int main()
{
    std::vector<int> v{ 10, 3, 0, 88, 101, 20 };
    heapSort(v);
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
}
