//Making use of a vector to be able to use .size()
#include <vector>
#include <iostream>
#include <math.h>


int two_crystal_balls(std::vector<bool> arr)
{
	const size_t jump_amount = std::floor(std::sqrt(arr.size()));
	size_t previous_index = 0;
	for (size_t i = 0; i < arr.size(); i += jump_amount)
	{
		if (arr[i])
			for (size_t ii = previous_index; ii < i && ii < arr.size(); ii++)
				if (arr[ii])
					return (ii);
		previous_index = i;
	}
    return -1;
}

int main(void)
{
    std::vector<bool> sorted_list = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    std::cout << "Results: " << two_crystal_balls(sorted_list) << std::endl;

	return (0);
}