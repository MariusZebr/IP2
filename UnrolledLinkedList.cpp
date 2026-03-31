#include "UnrolledLinkedList.h"

namespace datastructures
{
class UnrolledLinkedList::Impl
{
private:
    static const int NODE_CAPACITY;

public:
    class Node
    {
    public:
        int *arr;
        int numElements;
        Node* next;

        Node();
        ~Node();
    };

    // Core functions

    // Constructors/Destructors
    Impl();
    ~Impl();

    // Insert/Delete(first instance of) value
    void insert(int value);
    void remove(int value);

    // return position of value, -1 if not found
    int find(int value) const;

    // remove all elements
    void clear();

    // convert list to string
    std::string toString() const;

    // Comparison
    bool compare(const Impl* other, int& result) const;
    // result: -1 if this < other, 0 if equal, 1 if this > other

private:
    Node* head;      // pointer to first node
};

const int UnrolledLinkedList::Impl::NODE_CAPACITY = 4;

UnrolledLinkedList::Impl::Node::Node()
{
    numElements = 0;
    next = nullptr;
    arr = new int[NODE_CAPACITY];
}

UnrolledLinkedList::Impl::Node::~Node()
{
    delete[] arr;
}

UnrolledLinkedList::Impl::Impl()
{
    head = nullptr;
}

UnrolledLinkedList::Impl::~Impl()
{
    Node* curr = head;
    while (curr) {
        Node* tmp = curr;
        curr = curr->next;
        delete tmp; // Node destructor frees array
    }
}
}


