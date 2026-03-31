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

// Node Constructors/Destructors Definitions
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

// Implementation Method Definitions
UnrolledLinkedList::Impl::Impl()
{
    head = nullptr;
}

UnrolledLinkedList::Impl::~Impl()
{
    Node* curr = head;
    while (curr)
    {
        Node* tmp = curr;
        curr = curr->next;
        delete tmp; // Node destructor frees array
    }
}

void UnrolledLinkedList::Impl::insert(int value)
{
    // Case 1: if empty list, create first Node with the value
    if (!head) {
        head = new Node();
        head->arr[0] = value;
        head->numElements = 1;
        return;
    }

    // Go to last node
    Node* curr = head;
    while (curr->next)
        curr = curr->next;

    // Case 2: if last node has space, insert value
    if (curr->numElements < NODE_CAPACITY) {
        curr->arr[curr->numElements++] = value;
    }
    else {
        // Case 3: if Node full, split and carry one half to new node
        Node* newNode = new Node();

        int moveCount = NODE_CAPACITY / 2;

        // Move half of elements to new node
        for (int i = moveCount; i < NODE_CAPACITY; ++i) {
            newNode->arr[newNode->numElements++] = curr->arr[i];
        }

        // Shrink current node
        curr->numElements = moveCount;

        // Insert new value into new node
        newNode->arr[newNode->numElements++] = value;

        // Link new node
        curr->next = newNode;
    }
}


}


