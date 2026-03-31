#include <sstream>
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

    // Comparison
    int compare(const Impl* other) const;
    // return: -1 if this < other, 0 if equal, 1 if this > other

    // convert list to string
    std::string toString() const;

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
    // An exception?
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
    clear();
}

void UnrolledLinkedList::Impl::insert(int value)
{
    // Case 1: if empty list, create first Node with the value
    if (!head)
    {
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
    if (curr->numElements < NODE_CAPACITY)
    {
        curr->arr[curr->numElements++] = value;
    }
    else
    {
        // Case 3: if Node full, split and carry one half to new node
        Node* newNode = new Node();

        int moveCount = NODE_CAPACITY / 2;

        // Move half of elements to new node
        for (int i = moveCount; i < NODE_CAPACITY; ++i)
        {
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

void UnrolledLinkedList::Impl::remove(int value)
{
    Node* curr = head;
    Node* prev = nullptr;

    while (curr)
    {
        // Look for value in current(curr) node
        for (int i = 0; i < curr->numElements; ++i)
        {
            if (curr->arr[i] == value)
            {
                // Shift array elements left
                for (int j = i; j < curr->numElements - 1; ++j)
                {
                    curr->arr[j] = curr->arr[j + 1];
                }
                curr->numElements--;

                // Remove node if empty but not head
                if (curr->numElements == 0 && prev)
                {
                    prev->next = curr->next;
                    delete curr;
                }

                return; // removed first occurrence
            }
        }

        // Move to next node
        prev = curr;
        curr = curr->next;
    }
}

int UnrolledLinkedList::Impl::find(int value) const
{
    Node* curr = head;
    int pos = 0;

    while (curr)
    {
        for (int i = 0; i < curr->numElements; ++i)
        {
            if (curr->arr[i] == value)
                return pos; // found
            ++pos;
        }
        curr = curr->next;
    }

    return -1; // not found
}

void UnrolledLinkedList::Impl::clear()
{
    Node* curr = head;

    while (curr)
    {
        Node* tmp = curr;
        curr = curr->next;
        delete tmp;
    }

    head = nullptr;
}

int UnrolledLinkedList::Impl::compare(const Impl* other) const
{
    if (!other)
    {
        // An exception
    }
    Node* a = head;
    Node* b = other->head;

    int i = 0, j = 0;

    while (a && b)
    {
        // Compare elements inside one of nodes
        while (i < a->numElements && j < b->numElements)
        {
            if (a->arr[i] < b->arr[j])
            {
                return -1;
            }
            if (a->arr[i] > b->arr[j])
            {
                return 1;
            }
            ++i;
            ++j;
        }

        // Move to next node in a
        if (i >= a->numElements)
        {
            a = a->next;
            i = 0;
        }

        // Move to next node in b
        if (j >= b->numElements)
        {
            b = b->next;
            j = 0;
        }
    }

    // If one list ended, compare lengths
    int result;
    if (!a && !b)
    {
        result = 0; // equal
    }
    else if (!a)
    {
        result = -1; // a shorter
    }
    else
    {
        result = 1; // b shorter
    }

    return result;
}

std::string UnrolledLinkedList::Impl::toString() const
{
    Node* curr = head;
    std::stringstream ss;

    while (curr)
    {
        ss << curr->numElements << ": ";
        for (int i = 0; i < curr->numElements; ++i)
        {
            ss << curr->arr[i] << " ";
        }
        ss << "| ";  // separator for different nodes
        curr = curr->next;
    }

    return ss.str();
}

// UnrolledLinkedList Method Definitions
UnrolledLinkedList& UnrolledLinkedList::operator+=(const int value)
{
    pImpl->insert(value);
    return *this;
}

UnrolledLinkedList& UnrolledLinkedList::operator-=(const int value)
{
    pImpl->remove(value);
    return *this;
}

int UnrolledLinkedList::operator[](int value) const
{
    return pImpl->find(value);
}

void UnrolledLinkedList::operator!()
{
    pImpl->clear();
}

bool UnrolledLinkedList::operator==(const UnrolledLinkedList& other) const
{
    return (pImpl->compare(other.pImpl) == 0);
}

bool UnrolledLinkedList::operator!=(const UnrolledLinkedList& other) const
{
    return (pImpl->compare(other.pImpl) != 0);
}

bool UnrolledLinkedList::operator<(const UnrolledLinkedList& other) const
{
    return (pImpl->compare(other.pImpl) == -1);
}

bool UnrolledLinkedList::operator<=(const UnrolledLinkedList& other) const
{
    int result = pImpl->compare(other.pImpl);
    return (result == -1) || (result == 0);
}

bool UnrolledLinkedList::operator>(const UnrolledLinkedList& other) const
{
    return (pImpl->compare(other.pImpl) == 1);
}

bool UnrolledLinkedList::operator>=(const UnrolledLinkedList& other) const
{
    int result = pImpl->compare(other.pImpl);
    return (result == 1) || (result == 0);
}

std::string UnrolledLinkedList::toString() const
{
    return pImpl->toString();
}
}





