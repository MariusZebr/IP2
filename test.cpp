#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include "UnrolledLinkedList.h"

//#define TEST_MODE
#ifdef TEST_MODE


static int passed = 0;
static int failed = 0;

void report(std::ofstream& log, const std::string& name, bool ok)
{
    log << (ok ? "[PASS] " : "[FAIL] ") << name << std::endl;
    if (ok)
        ++passed;
    else
        ++failed;
}

int main()
{
    std::ofstream fout;
    try
    {
        fout.open("log.txt");

        fout << "Insertion Tests" << std::endl;
        Datastructures::UnrolledLinkedList list1;
        list1 += 1;
        report(fout, "operator +=: toString after 1st insert", list1.toString() == "|1: 1|");
        list1 += 2;
        list1 += 3;
        list1 += 4;
        report(fout, "operator +=: toString after 4th insert", list1.toString() == "|4: 1 2 3 4|");
        list1 += 5;
        report(fout, "operator +=: toString after 5th insert", list1.toString() == "|2: 1 2|3: 3 4 5|");
        !list1;
        list1 += -1;
        report(fout, "operator +=: toString after 6th insert", list1.toString() == "|1: -1|");

        fout << "\nDeletion Tests" << std::endl;
        Datastructures::UnrolledLinkedList list2;
        list2 += 1;
        list2 -= 1;
        report(fout, "operator -=: toString after 1st deletion", list2.toString() == "");
        !list2;
        list2 += 1;
        list2 += 2;
        list2 -= 2;
        report(fout, "operator -=: toString after 2nd deletion", list2.toString() == "|1: 1|");
        !list2;
        list2 += 1;
        list2 += 2;
        list2 -= 1;
        report(fout, "operator -=: toString after 3rd deletion", list2.toString() == "|1: 2|");
        !list2;
        list2 += 1;
        list2 += 2;
        list2 += 3;
        list2 += 4;
        list2 += 5;
        list2 -= 5;
        report(fout, "operator -=: toString after 4th deletion", list2.toString() == "|2: 1 2|2: 3 4|");
        !list2;
        list2 += 1;
        list2 += 2;
        list2 += 3;
        list2 += 4;
        list2 += 5;
        list2 -= 1;
        report(fout, "operator -=: toString after 5th deletion", list2.toString() == "|1: 2|3: 3 4 5|");
        !list2;
        list2 += 1;
        list2 += 3;
        list2 += 1;
        list2 -= 1;
        report(fout, "operator -=: toString after 6th deletion", list2.toString() == "|2: 3 1|");
        !list2;
        list2 += 1;
        list2 += 2;
        list2 += 3;
        list2 += 4;
        list2 += 1;
        list2 += 6;
        list2 -= 1;
        report(fout, "operator -=: toString after 7th deletion", list2.toString() == "|1: 2|4: 3 4 1 6|");
        !list2;
        list2 += 1;
        list2 += 2;
        list2 -= 3;
        report(fout, "operator -=: toString after 8th deletion", list2.toString() == "|2: 1 2|");
        !list2;
        list2 -= 3;
        report(fout, "operator -=: toString after 9th deletion", list2.toString() == "");
        !list2;
        list2 += 1;
        list2 += 2;
        list2 += 3;
        list2 += 4;
        list2 += 5;
        list2 -= 1;
        list2 -= 2;
        report(fout, "operator -=: toString after 10th deletion", list2.toString() == "|3: 3 4 5|");
        !list2;
        list2 += 1;
        list2 += 2;
        list2 += 3;
        list2 += 4;
        list2 += 5;
        list2 += 6;
        list2 += 7;
        list2 -= 3;
        list2 -= 4;
        report(fout, "operator -=: toString after 11th deletion", list2.toString() == "|2: 1 2|3: 5 6 7|");
        !list2;

        list2 += -1;
        list2 += 2;
        list2 -= -1;
        report(fout, "operator -=: toString after 12th deletion", list2.toString() == "|1: 2|");
        !list2;

        fout << "\nDeep Copy Tests" << std::endl;
        list1 = list2;
        report(fout, "operator =: toString after 1st deep copy", list1.toString() == "" && list2.toString() == "");
        list1 += 1;
        report(fout, "operator =: toString after 1st deep copy", list1.toString() == "|1: 1|" && list2.toString() == "");
        !list1;
        !list2;

        list1 += 1;
        list2 += 2;
        list1 = list2;
        report(fout, "operator =: toString after 2nd deep copy", list1.toString() == "|1: 2|" && list2.toString() == "|1: 2|");
        list1 += 3;
        report(fout, "operator =: toString after 2nd deep copy", list1.toString() == "|2: 2 3|" && list2.toString() == "|1: 2|");
        !list1;
        !list2;

        list1 += 1;
        list1 += 2;
        list2 += 1;
        list2 += 2;
        list2 += 3;
        list2 += 4;
        list2 += 5;
        list1 = list2;
        report(fout, "operator =: toString after 3rd deep copy", list1.toString() == "|2: 1 2|3: 3 4 5|" && list2.toString() == "|2: 1 2|3: 3 4 5|");
        list2 -= 4;
        report(fout, "operator =: toString after 3rd deep copy", list1.toString() == "|2: 1 2|3: 3 4 5|" && list2.toString() == "|2: 1 2|2: 3 5|");
        !list1;
        !list2;

        list2 += 1;
        list2 += 2;
        list2 += 3;
        list2 += 4;
        list2 += 5;
        list2 = list2;
        report(fout, "operator =: toString after 4th deep copy", list2.toString() == "|2: 1 2|3: 3 4 5|");
        list2 += 99;

        fout << "\nSearch by Value Tests" << std::endl;
        Datastructures::UnrolledLinkedList list3;
        // Exception Tests
        try
        {
            int num = list3[1];
        }
        catch(Datastructures::ValueNotFound& e)
        {
            fout << e.what() << std::endl;
            fout << "Succesfully caught 1st ValueNotFound exception" << std::endl;
        }
        !list3;
        fout << std::endl;

        list3 += 2;
        try
        {
            int num = list3[1];
        }
        catch(Datastructures::ValueNotFound& e)
        {
            fout << e.what() << std::endl;
            fout << "Succesfully caught 2nd ValueNotFound exception" << std::endl;
        }
        !list3;
        fout << std::endl;

        list3 += 1;
        list3 += 2;
        list3 += 3;
        list3 += 4;
        list3 += 5;
        try
        {
            int num = list3[6];
        }
        catch(Datastructures::ValueNotFound& e)
        {
            fout << e.what() << std::endl;
            fout << "Succesfully caught 3rd ValueNotFound exception" << std::endl;
        }
        !list3;
        fout << std::endl;

        list3 += 1;
        report(fout, "operator[]: position after 1st search", list3[1] == 0);
        !list3;

        list3 += 1;
        list3 += 2;
        list3 += 3;
        list3 += 4;
        list3 += 5;
        report(fout, "operator[]: position after 2nd search", list3[5] == 4);
        !list3;

        list3 += 1;
        list3 += 1;
        list3 += 3;
        list3 += 4;
        list3 += 5;
        report(fout, "operator[]: position after 3rd search", list3[1] == 0);
        !list3;

        list3 += 1;
        list3 += 2;
        list3 += 3;
        list3 += 4;
        list3 += 1;
        report(fout, "operator[]: position after 4th search", list3[1] == 0);
        !list3;

        list3 += -1;
        list3 += 2;
        report(fout, "operator[]: position after 5th search", list3[-1] == 0);
        !list3;

        fout << "\nGet Value Tests" << std::endl;
        // Exception Tests
        try
        {
            int num = list3.at(0);
        }
        catch(std::out_of_range& e)
        {
            fout << e.what() << std::endl;
            fout << "Succesfully caught 1st out_of_range exception" << std::endl;
        }
        !list3;
        fout << std::endl;

        list3 += 2;
        try
        {
            int num = list3.at(1);
        }
        catch(std::out_of_range& e)
        {
            fout << e.what() << std::endl;
            fout << "Succesfully caught 2nd out_of_range exception" << std::endl;
        }
        !list3;
        fout << std::endl;

        list3 += 1;
        list3 += 2;
        list3 += 3;
        list3 += 4;
        list3 += 5;
        try
        {
            int num = list3.at(6);
        }
        catch(std::out_of_range& e)
        {
            fout << e.what() << std::endl;
            fout << "Succesfully caught 3rd out_of_range exception" << std::endl;
        }
        !list3;
        fout << std::endl;

        list3 += 1;
        report(fout, "at(): position after 1st search", list3.at(0) == 1);
        !list3;

        list3 += 1;
        list3 += 2;
        list3 += 3;
        list3 += 4;
        list3 += 5;
        report(fout, "at(): position after 2nd search", list3.at(4) == 5);
        !list3;

        list3 += -1;
        list3 += 2;
        report(fout, "at():  position after 3rd search", list3.at(0) == -1);
        !list3;

        fout << "\nEdit Tests" << std::endl;
        // Exception Tests
        Datastructures::UnrolledLinkedList list4;
        try
        {
            list4 *= {0, 4};
        }
        catch(std::out_of_range& e)
        {
            fout << e.what() << std::endl;
            fout << "Succesfully caught 1st out_of_range exception" << std::endl;
        }
        !list4;
        fout << std::endl;

        list4 += 1;
        try
        {
            list4 *= {-1, 45};
        }
        catch(std::out_of_range& e)
        {
            fout << e.what() << std::endl;
            fout << "Succesfully caught 2nd out_of_range exception" << std::endl;
        }
        !list4;
        fout << std::endl;

        list4 += 1;
        list4 += 2;
        try
        {
            list4 *= {100, 2};
        }
        catch(std::out_of_range& e)
        {
            fout << e.what() << std::endl;
            fout << "Succesfully caught 3rd out_of_range exception" << std::endl;
        }
        !list4;
        fout << std::endl;

        list4 += 1;
        list4 *= {0, 2};
        report(fout, "operator *=: position after 1st edit", list4.toString() == "|1: 2|");
        !list4;

        list4 += 1;
        list4 += 2;
        list4 += 3;
        list4 += 4;
        list4 += 5;
        list4 *= {4, 6};
        report(fout, "operator *=: toString after 2nd edit", list4.toString() == "|2: 1 2|3: 3 4 6|");
        !list4;

        list4 += -1;
        list4 += 2;
        list4 *= {0, -3};
        report(fout, "operator *=: toString after 3rd edit", list4.toString() == "|2: -3 2|");
        !list4;

        fout << "\nClear Tests" << std::endl;
        Datastructures::UnrolledLinkedList list5;
        !list5;
        report(fout, "operator!: toString after 1st clear", list5.toString() == "");

        !list5;
        !list5;
        report(fout, "operator!: toString after 2nd clear", list5.toString() == "");

        list5 += 1;
        !list5;
        report(fout, "operator!: toString after 3rd clear", list5.toString() == "");

        list5 += 1;
        list5 += 2;
        list5 += 3;
        list5 += 4;
        list5 += 5;
        !list5;
        report(fout, "operator!: toString after 4th clear", list5.toString() == "");

        fout << "\nComparison Tests" << std::endl;
        Datastructures::UnrolledLinkedList list6_1;
        Datastructures::UnrolledLinkedList list6_2;

        report(fout, "operator ==: after 1st comparison", (list6_1 == list6_2) == true);
        report(fout, "operator !=: after 1st comparison", (list6_1 != list6_2) == false);
        report(fout, "operator <: after 1st comparison", (list6_1 < list6_2) == false);
        report(fout, "operator <=: after 1st comparison", (list6_1 <= list6_2) == true);
        report(fout, "operator >: after 1st comparison", (list6_1 > list6_2) == false);
        report(fout, "operator >=: after 1st comparison", (list6_1 >= list6_2) == true);
        fout << std::endl;

        list6_1 += 1;
        list6_2 += 1;
        report(fout, "operator ==: after 2nd comparison", (list6_1 == list6_2) == true);
        report(fout, "operator !=: after 2nd comparison", (list6_1 != list6_2) == false);
        report(fout, "operator <: after 2nd comparison", (list6_1 < list6_2) == false);
        report(fout, "operator <=: after 2nd comparison", (list6_1 <= list6_2) == true);
        report(fout, "operator >: after 2nd comparison", (list6_1 > list6_2) == false);
        report(fout, "operator >=: after 2nd comparison", (list6_1 >= list6_2) == true);
        !list6_1;
        !list6_2;
        fout << std::endl;

        list6_1 += 1;
        list6_2 += 2;
        report(fout, "operator ==: after 3rd comparison", (list6_1 == list6_2) == false);
        report(fout, "operator !=: after 3rd comparison", (list6_1 != list6_2) == true);
        report(fout, "operator <: after 3rd comparison", (list6_1 < list6_2) == true);
        report(fout, "operator <=: after 3rd comparison", (list6_1 <= list6_2) == true);
        report(fout, "operator >: after 3rd comparison", (list6_1 > list6_2) == false);
        report(fout, "operator >=: after 3rd comparison", (list6_1 >= list6_2) == false);
        !list6_1;
        !list6_2;
        fout << std::endl;

        list6_1 += 0;
        list6_1 += 1;
        list6_2 += 0;
        list6_2 += 2;
        report(fout, "operator ==: after 4th comparison", (list6_1 == list6_2) == false);
        report(fout, "operator !=: after 4th comparison", (list6_1 != list6_2) == true);
        report(fout, "operator <: after 4th comparison", (list6_1 < list6_2) == true);
        report(fout, "operator <=: after 4th comparison", (list6_1 <= list6_2) == true);
        report(fout, "operator >: after 4th comparison", (list6_1 > list6_2) == false);
        report(fout, "operator >=: after 4th comparison", (list6_1 >= list6_2) == false);
        !list6_1;
        !list6_2;
        fout << std::endl;

        list6_1 += 1;
        list6_1 += 1;
        list6_1 += 1;
        list6_1 += 1;
        list6_1 += 1;

        list6_2 += 1;
        list6_2 += 1;
        list6_2 += 1;
        list6_2 += 1;
        list6_2 += 2;
        report(fout, "operator ==: after 5th comparison", (list6_1 == list6_2) == false);
        report(fout, "operator !=: after 5th comparison", (list6_1 != list6_2) == true);
        report(fout, "operator <: after 5th comparison", (list6_1 < list6_2) == true);
        report(fout, "operator <=: after 5th comparison", (list6_1 <= list6_2) == true);
        report(fout, "operator >: after 5th comparison", (list6_1 > list6_2) == false);
        report(fout, "operator >=: after 5th comparison", (list6_1 >= list6_2) == false);
        !list6_1;
        !list6_2;
        fout << std::endl;

        list6_2 += 2;
        report(fout, "operator ==: after 6th comparison", (list6_1 == list6_2) == false);
        report(fout, "operator !=: after 6th comparison", (list6_1 != list6_2) == true);
        report(fout, "operator <: after 6th comparison", (list6_1 < list6_2) == true);
        report(fout, "operator <=: after 6th comparison", (list6_1 <= list6_2) == true);
        report(fout, "operator >: after 6th comparison", (list6_1 > list6_2) == false);
        report(fout, "operator >=: after 6th comparison", (list6_1 >= list6_2) == false);
        !list6_1;
        !list6_2;
        fout << std::endl;

        list6_1 += 1;
        list6_1 += 2;
        list6_1 += 3;
        list6_1 += 4;

        list6_2 += 1;
        list6_2 += 2;
        list6_2 += 3;
        list6_2 += 4;
        list6_2 += 5;
        report(fout, "operator ==: after 7th comparison", (list6_1 == list6_2) == false);
        report(fout, "operator !=: after 7th comparison", (list6_1 != list6_2) == true);
        report(fout, "operator <: after 7th comparison", (list6_1 < list6_2) == true);
        report(fout, "operator <=: after 7th comparison", (list6_1 <= list6_2) == true);
        report(fout, "operator >: after 7th comparison", (list6_1 > list6_2) == false);
        report(fout, "operator >=: after 7th comparison", (list6_1 >= list6_2) == false);
        fout << std::endl;
        !list6_1;
        !list6_2;

        list6_1 += -2;
        list6_2 += -1;
        report(fout, "operator ==: after 8th comparison", (list6_1 == list6_2) == false);
        report(fout, "operator !=: after 8th comparison", (list6_1 != list6_2) == true);
        report(fout, "operator <: after 8th comparison", (list6_1 < list6_2) == true);
        report(fout, "operator <=: after 8th comparison", (list6_1 <= list6_2) == true);
        report(fout, "operator >: after 8th comparison", (list6_1 > list6_2) == false);
        report(fout, "operator >=: after 8th comparison", (list6_1 >= list6_2) == false);
        !list6_1;
        !list6_2;

        fout << "\nGet Size Tests" << std::endl;
        Datastructures::UnrolledLinkedList list7;
        report(fout, "getSize(): 1st", list7.getSize() == 0);
        list7 += 1;
        report(fout, "getSize(): 2nd", list7.getSize() == 1);
        list7 += 2;
        list7 += 3;
        list7 += 4;
        list7 += 5;
        report(fout, "getSize(): 2nd", list7.getSize() == 5);
    }
    catch(...)
    {
        fout << "Unexpected error occurred" << std::endl;
    }
    return 0;
}

#endif // TEST_MODE
