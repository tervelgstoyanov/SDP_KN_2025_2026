#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>

std::vector<int> twoSum(const std::vector<int>& arr, int target)
{
	std::unordered_map<int, int> m;

	for (int i = 0; i < arr.size(); i++)
	{
		if (m.find(arr[i]) != m.end())
		{
			return { i, m[arr[i]] };
		}

		m[(target - arr[i])] = i;
	}

	return {};
}

int main()
{
	std::vector<int> arr = { 1, 2, 7, 12 };
	for (int index : twoSum(arr, 9))
	{
		std::cout << index << std::endl;
	}
}
