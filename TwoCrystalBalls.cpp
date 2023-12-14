//Making use of a vector to be able to use .size()
#include <vector>
#include <iostream>
#include <math.h>

//Walk the array by square root of N till we find true.
//when true is found walk from previous false value till we find a true value so the second crystal ball "breaks"
//if found return index
int two_crystal_balls(std::vector<bool> arr)
{
	const size_t jump_amount = std::floor(std::sqrt(arr.size()));
	size_t previous_index = 0;
	for (size_t i = 0; i < arr.size(); i += jump_amount)
	{
		if (arr[i])
            break;
		previous_index = i;
	}

	for (size_t i = previous_index; i < (previous_index + jump_amount) && i < arr.size(); i++)
    {
		if (arr[i])
			return i;
    }
    return -1;
}

int main(void)
{
    std::vector<bool> sorted_list = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    std::cout << "Results: " << two_crystal_balls(sorted_list) << std::endl;

	return (0);
}