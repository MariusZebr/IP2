#ifndef UNROLLEDLINKEDLIST_H_769124
#define UNROLLEDLINKEDLIST_H_769124

#include <string>

namespace datastructures
{
class UnrolledLinkedList
{
public:
    // Constructors/Destructors
    UnrolledLinkedList();
    ~UnrolledLinkedList();

    // Insert/Delete(first instance) by value
    UnrolledLinkedList& operator+=(const int value);
    UnrolledLinkedList& operator-=(const int value);

    // Search by Value
    int operator[](const int value) const;

    // Edit *= implementation

    // Clear Object
    void operator!();

    // Lexicographical Comparisons of Objects
    bool operator==(const UnrolledLinkedList& other) const;
    bool operator!=(const UnrolledLinkedList& other) const;
    bool operator< (const UnrolledLinkedList& other) const;
    bool operator<=(const UnrolledLinkedList& other) const;
    bool operator> (const UnrolledLinkedList& other) const;
    bool operator>=(const UnrolledLinkedList& other) const;

    std::string toString() const;

private:
    class Impl;
    Impl* pImpl;
};
}


#endif // UNROLLEDLINKEDLIST_H_769124


