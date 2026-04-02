#ifndef UNROLLEDLINKEDLIST_H_769124
#define UNROLLEDLINKEDLIST_H_769124

#include <string>
#define RUN_DEBUG

namespace datastructures
{
class UnrolledLinkedList
{
public:
    // Constructor/Destructor
    UnrolledLinkedList();
    ~UnrolledLinkedList();

    // Copy Constructor
    UnrolledLinkedList(const UnrolledLinkedList& other);
    // Deep copy
    UnrolledLinkedList& operator=(const UnrolledLinkedList& other);

    // Insert/Delete(first instance) by value
    UnrolledLinkedList& operator+=(const int value);
    UnrolledLinkedList& operator-=(const int value);

    // Search by Value
    int operator[](const int value) const;

    // Replace value at index with new value
    UnrolledLinkedList& operator*=(std::pair<int,int> edit);

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


