#include "UnrolledLinkedList.h"

//#define DEMO_MODE

#ifdef DEMO_MODE
int main()
{
    try
    {
        // Insertion tests
        std::cout << "Insertion tests" << std::endl;
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

        // Deletions Tests
        std::cout << "\nDeletion Tests" << std::endl;
        list1 -= 5;
        std::cout << "list1: " << list1.toString() << std::endl;
        list1 -= 1;
        std::cout << "list1: " << list1.toString() << std::endl;
        list1 -= 2;
        std::cout << "list1: " << list1.toString() << std::endl;

        // Copy Tests
        std::cout << "\nCopy Tests" << std::endl;
        datastructures::UnrolledLinkedList list2;
        list2 = list1;
        std::cout << "list1: " << list1.toString() << std::endl;
        std::cout << "list2: " << list2.toString() << std::endl;
        std::cout << std::endl;

        list2 += 98;
        std::cout << "list1: " << list1.toString() << std::endl;
        std::cout << "list2: " << list2.toString() << std::endl;

        // Search by Value Tests
        std::cout << "\nSearch by Value Tests" << std::endl;
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


        // Edit Tests
        std::cout << "\nEdit Tests" << std::endl;
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

        // Clear Tests
        std::cout << "\nClear Tests" << std::endl;
        std::cout << "list3: " << list3.toString() << std::endl;
        !list3;
        std::cout << "list3: " << list3.toString() << std::endl;
        !list3;
        std::cout << "list3: " << list3.toString() << std::endl;
        list3 += 2;
        std::cout << "list3: " << list3.toString() << std::endl;

        // Comparison Tests
        std::cout << "\nComparison Tests" << std::endl;
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
        cout << "Unexpected error occurred" << endl;
    }
    return 0;
}
#endif
