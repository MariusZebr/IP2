#include <iostream>
#include <exception>
#include <stdexcept>

#include "UnrolledLinkedList.h"

//#define DEMO_MODE
#ifdef DEMO_MODE
int main()
{
    try
    {
        // Insertion Demo
        std::cout << "Insertion Demo" << std::endl;
        datastructures::UnrolledLinkedList list1;
        list1 += 1;
        std::cout << "list1: " << list1.toString() << std::endl;
        list1 += 1;
        std::cout << "list1: " << list1.toString() << std::endl;
        list1 += 2;
        std::cout << "list1: " << list1.toString() << std::endl;
        list1 += 3;
        std::cout << "list1: " << list1.toString() << std::endl;
        list1 += 4;
        std::cout << "list1: " << list1.toString() << std::endl;
        list1 += 5;
        std::cout << "list1: " << list1.toString() << std::endl;
        list1 += 5;
        std::cout << "list1: " << list1.toString() << std::endl;

        // Deletions Demo
        std::cout << "\nDeletion Demo" << std::endl;
        list1 -= 5;
        std::cout << "list1: " << list1.toString() << std::endl;
        list1 -= 1;
        std::cout << "list1: " << list1.toString() << std::endl;
        list1 -= 2;
        std::cout << "list1: " << list1.toString() << std::endl;

        // Copy Demo
        std::cout << "\nCopy Demo" << std::endl;
        datastructures::UnrolledLinkedList list2;
        list2 = list1;
        std::cout << "list1: " << list1.toString() << std::endl;
        std::cout << "list2: " << list2.toString() << std::endl;
        std::cout << std::endl;

        list2 += 98;
        std::cout << "list1: " << list1.toString() << std::endl;
        std::cout << "list2: " << list2.toString() << std::endl;

        // Search by Value Demo
        std::cout << "\nSearch by Value Demo" << std::endl;
        std::cout << "list2: " << list2.toString() << std::endl;
        std::cout << "Position of 98 in list2: " << list2[98] << std::endl;
        datastructures::UnrolledLinkedList list3;
        list3 += 1;
        list3 += 1;
        std::cout << "list3: " << list3.toString() << std::endl;
        std::cout << "Position of 1 in list3: " << list3[1] << std::endl;
        list3 += 2;
        list3 += 3;
        list3 += 4;
        std::cout << "list3: " << list3.toString() << std::endl;
        std::cout << "(testing when NODE_CAPACITY = 4) Position of 4 in list3: " << list3[4] << std::endl;
        // Custom Exception Test
        try
        {
            std::cout << "Position of 98 in list3: " << list3[98] << std::endl;
        }
        catch(datastructures::ValueNotFound& e)
        {
            std::cout << "Succesfully caught ValueNotFound exception" << std::endl;
        }


        // Edit Demo
        std::cout << "\nEdit Demo" << std::endl;
        std::cout << "list3: " << list3.toString() << std::endl;
        list3 *= {0, 5};
        std::cout << "list3: " << list3.toString() << std::endl;
        list3 *= {2, 99};
        std::cout << "list3: " << list3.toString() << std::endl;
        // Exception Tests
        try
        {
            list3 *= {-2, 99};
        }
        catch(std::out_of_range& e)
        {
            std::cout << "Succesfully caught out_of_range exception" << std::endl;
        }

        try
        {
            list3 *= {1000, 99};
        }
        catch(std::out_of_range& e)
        {
            std::cout << "Succesfully caught out_of_range exception" << std::endl;
        }

        // Clear Demo
        std::cout << "\nClear Demo" << std::endl;
        std::cout << "list3: " << list3.toString() << std::endl;
        !list3;
        std::cout << "list3: " << list3.toString() << std::endl;
        !list3;
        std::cout << "list3: " << list3.toString() << std::endl;
        list3 += 2;
        std::cout << "list3: " << list3.toString() << std::endl;

        // Comparison Tests
        std::cout << "\nComparison Demo" << std::endl;
        datastructures::UnrolledLinkedList list4;
        list4 += 4;
        list3 -= 2;
        list3 += 3;
        std::cout << "list1: " << list1.toString() << std::endl;
        std::cout << "list2: " << list2.toString() << std::endl;
        std::cout << "list3: " << list3.toString() << std::endl;
        std::cout << "list4: " << list4.toString() << std::endl;
        std::cout << std::endl;

        std::cout << "list2 > list3: " << (list2 > list3) << std::endl;
        std::cout << "list2 < list3: " << (list2 < list3) << std::endl;
        std::cout << "list2 >= list3: " << (list2 >= list3) << std::endl;
        std::cout << "list2 <= list3: " << (list2 <= list3) << std::endl;
        std::cout << "list2 == list3: " << (list2 == list3) << std::endl;
        std::cout << "list2 != list3: " << (list2 != list3) << std::endl;
        std::cout << std::endl;

        std::cout << "list2 >= list2: " << (list2 >= list2) << std::endl;
        std::cout << "list2 <= list2: " << (list2 <= list2) << std::endl;
        std::cout << "list2 == list2: " << (list2 == list2) << std::endl;
        std::cout << "list2 != list2: " << (list2 != list2) << std::endl;
        std::cout << std::endl;

        std::cout << "list1 > list2: " << (list1 > list2) << std::endl;
        std::cout << "list1 < list2: " << (list1 < list2) << std::endl;
        std::cout << "list1 >= list2: " << (list1 >= list2) << std::endl;
        std::cout << "list1 <= list2: " << (list1 <= list2) << std::endl;
        std::cout << "list1 == list2: " << (list1 == list2) << std::endl;
        std::cout << "list1 != list2: " << (list1 != list2) << std::endl;
    }
    catch(...)
    {
        std::cout << "Unexpected error occurred" << std::endl;
    }
    return 0;
}
#endif // DEMO_MODE
