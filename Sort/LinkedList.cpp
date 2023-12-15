#include "LinkedList.h"



int main()
{
    linked_list<int> test(5);
    test.append(6);
    test.insertAt(7, 1);
    test.print();
    test.removeAt(1);
    std::cout << "\n\n\n" << std::endl;
    test.print();

    std::cout << "Size: " << test.length() << std::endl;
    std::cout << "Value: " << test.get(1) << std::endl;

    return 0;
}