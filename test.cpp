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

        fout << "Insertion tests" << std::endl;
        datastructures::UnrolledLinkedList list1;
        list1 += 1;
        report(fout, "operator +=: toString after 1 insert", list1.toString() == "|1: 1|");
        list1 += 2;
        list1 += 3;
        list1 += 4;
        report(fout, "operator +=: toString after 4th insert", list1.toString() == "|4: 1 2 3 4|");
        list1 += 5;
        report(fout, "operator +=: toString after 5th insert", list1.toString() == "|2: 1 2|3: 3 4 5|");
    }
    catch(...)
    {
        fout << "Unexpected error occurred" << std::endl;
    }
    return 0;
}

#endif // TEST_MODE
