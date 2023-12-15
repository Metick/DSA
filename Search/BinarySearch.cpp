//Making use of a vector to be able to use .size()
#include <vector>
#include <iostream>

//We're always under the assumption that the array has already been sorted for this way to work.
//While Lower is not higher than Hi (So when it overlaps)
//Get the middle point by doing Low + ((hi - low) / 2)
//Example : 0 + ((20 - 0) / 2) = 10, middle point first loop is 10, after that it's either
//Example : 11 + ((20 - 11) / 2) == 4 + 11 == 15 middle point. 
//It check if the middle point value is smaller or higher than value we're looking for
//If it's smaller than that means the value we're looking for is low - middle point.
//Hence why each time we do low = middle + 1 (Inclusive) 
//and for high we just do to middle point as that's (Exclusive)
//Keep repeating this till either value found or we overlap for result.
bool binary_search(std::vector<int> arr, int value)
{
    size_t hi = arr.size();
    size_t low = 0; 
    while (low < hi)
    {
        size_t middle = (low + ((hi - low) / 2));
        if (arr[middle] == value)
            return true;
        else if (arr[middle] < value)
            low = middle + 1;
        else
            hi = middle;
    }
    return false;
}

int main(void)
{
    std::vector<int> sorted_list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    std::cout << "Results: " << binary_search(sorted_list, 9) << std::endl;
    return 0;
}