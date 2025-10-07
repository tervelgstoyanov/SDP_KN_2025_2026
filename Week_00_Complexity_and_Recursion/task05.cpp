#include <iostream>
#include <cstdlib>
#include <ctime>

void printArray(const int * const arr, const int size)
{
    if (arr == nullptr || size == 0)
        return;
    
    std::cout << arr[0];
    for (int j = 1; j < size; ++j)
        std::cout << ' ' << arr[j];
    std::cout << std::endl;
}

void fillArray(int * const arr, const int size)
{
    if (arr == nullptr || size == 0)
        return;
    
    for (int i = 0; i < size; ++i)
        arr[i] = std::rand();
}

void merge(
    int * const arr, const int size,
    const int from, const int mid, const int to,
    int * const helper
) {
    int idx1 = from, idx2 = from;
    for (; idx2 <= mid; ++idx2)
        helper[idx2] = arr[idx2];
    
    for (int j = idx2; j <= to; ++j)
        helper[j] = arr[j];

    for (int k = from; k <= to; ++k)
    {
        if (idx2 > to || (idx1 <= mid && helper[idx1] < helper[idx2]))
        {
            arr[k] = helper[idx1];
            idx1 += 1;
        }
        else
        {
            arr[k] = helper[idx2];
            idx2 += 1;
        }
    }
}

void mergeSort(
    int * const arr, const int size,
    const int from, const int to,
    int * const helper
) {
    if (from >= to)
        return;

    int mid = (from + to) / 2;
    mergeSort(arr, size, from, mid, helper);
    mergeSort(arr, size, mid + 1, to, helper);
    merge(arr, size, from, mid, to, helper);
}

int main()
{
    std::srand(std::time(NULL));

    int arr[23], helper[23],
        size = sizeof(arr) / sizeof(arr[0]);
    int from = 0, to = size - 1;
    fillArray(arr, size);
    
    std::cout << "Original array:\n";
    printArray(arr, size);
    
    mergeSort(arr, size, from, to, helper);
    
    std::cout << "Sorted array:\n";
    printArray(arr, size);
    
    return 0;
}