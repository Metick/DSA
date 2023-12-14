#include <vector>
#include <iostream>

void BubbleSort(std::vector<int> &arr)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        for (size_t ii = 0; ii < arr.size() - 1 - i; ii++)
        {
            if(arr[ii] > arr[ii + 1])
            {
                int tmp = arr[ii];
                arr[ii] = arr[ii + 1];
                arr[ii + 1] = tmp;
            }
        }  
    }
    
}

int main(void)
{
    std::vector<int> arr = {5, 8, 1, 9, 7, 12, 8, 86, 62, 11, 26, 41, 75, 92, 125, 1, 0, 62};
    BubbleSort(arr);
    for (size_t i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << std::endl;
    }
    
    return 0;
}