
//O(N), a linear increase in time based on N
//Making use of a vector to be able to use .size()
#include <vector>
#include <iostream>

bool linear_search(std::vector<int> arr, int value)
{
	for (size_t i = 0; i < arr.size(); i++)
	{
		if (arr[i] == value)
			return true;
	}
	return false;
}

int main(void)
{
	std::vector<int> int_array = {8, 1, 5, 6, 77, 101, 8163, 81,4174 ,111 ,1263 ,7};
	if (linear_search(int_array, 81))
		std::cout << "Found value in array" << std::endl;
	else
		std::cout << "Failed to find value in array" << std::endl;

	return (0);
}