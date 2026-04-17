#ifndef UNROLLEDLINKEDLIST_H_769124
#define UNROLLEDLINKEDLIST_H_769124
// ChatGPT and help from a colleague was used to help develop and debug
// portions of this implementation, including operator implementations

#include <string>
#define RUN_DEBUG

namespace Datastructures
{
    // Custom Exception
    class ValueNotFound : public std::runtime_error
    {
    public:
        ValueNotFound(const std::string &message);
    };

    class UnrolledLinkedList
    {
    private:
        class Impl;
        Impl *pImpl;

    public:
        // Constructor/Destructor
        UnrolledLinkedList();
        ~UnrolledLinkedList();

        // Copy Constructor
        UnrolledLinkedList(const UnrolledLinkedList &other);
        // Deep copy
        UnrolledLinkedList &operator=(const UnrolledLinkedList &other);

        // Insert/Delete(first instance) by value
        UnrolledLinkedList &operator+=(const int value);
        UnrolledLinkedList &operator-=(const int value);

        // Search by Value and return position
        int operator[](const int value) const;

        // Replace value at index with new value
        UnrolledLinkedList &operator*=(std::pair<int, int> edit);

        // Clear Object
        void operator!();

        // Lexicographical Comparisons of Objects
        bool operator==(const UnrolledLinkedList &other) const;
        bool operator!=(const UnrolledLinkedList &other) const;
        bool operator<(const UnrolledLinkedList &other) const;
        bool operator<=(const UnrolledLinkedList &other) const;
        bool operator>(const UnrolledLinkedList &other) const;
        bool operator>=(const UnrolledLinkedList &other) const;

        std::string toString() const;
    };
}

#endif // UNROLLEDLINKEDLIST_H_769124
