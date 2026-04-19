#include <string>
#include <sstream>
#include <utility>
#include <exception>
#include <stdexcept>
#include "UnrolledLinkedList.h"

namespace Datastructures
{

    // Custom Exception
    ValueNotFound::ValueNotFound(const std::string &message)
        : std::runtime_error(message)
    {
    }

    class UnrolledLinkedList::Impl
    {
    private:
        static const int NODE_CAPACITY;

    public:
        class Node
        {
        public:
            // Fields
            int *arr;
            int numElements;
            Node *next;

            // Constructor
            Node();

            // Copy Constructor
            Node(const Node &other);

            // Destructor
            ~Node();
        };

    private:
        Node *head; // pointer to first node

    public:
        // Core Functions

        // Constructor
        Impl();

        // Copy Constructor
        Impl(const Impl &other);

        // Destructor
        ~Impl();

        // Insert/Delete(first instance of) value
        void insert(int value);
        void remove(int value);

        // Return position of value, ValueNotFound exception if not found
        int find(int value) const;

        // Return value at the position
        int getValue(int index) const;

        // Replace value at index with newValue
        void edit(int index, int newValue);

        // Remove all elements
        void clear();

        // Comparison
        int compare(const Impl *other) const;
        // Return: -1 if this < other, 0 if equal, 1 if this > other

        // Get Current Size of UnrolledLinkedList
        int getSize() const;

        // Convert list to string
        std::string toString() const;
    };

    const int UnrolledLinkedList::Impl::NODE_CAPACITY = 4;

    // Definitions

    // Node Constructor
    UnrolledLinkedList::Impl::Node::Node()
    {
        numElements = 0;
        next = nullptr;
        arr = new int[NODE_CAPACITY];
    }

    UnrolledLinkedList::Impl::Node::Node(const Node &other)
    {
        numElements = other.numElements;
        arr = new int[NODE_CAPACITY];
        for (int i = 0; i < numElements; ++i)
            arr[i] = other.arr[i];
        next = nullptr; // don't copy next yet
    }

    UnrolledLinkedList::Impl::Node::~Node()
    {
        delete[] arr;
    }

    // Implementation Methods
    UnrolledLinkedList::Impl::Impl()
    {
        head = nullptr;
    }

    UnrolledLinkedList::Impl::Impl(const Impl &other)
    {
        head = nullptr;
        Node *tail = nullptr;
        Node *currOther = other.head;

        while (currOther)
        {
            Node *newNode = new Node(*currOther); // newNode is a pointer to just made Node
            newNode->next = nullptr;

            if (!head) // For first node
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                // next of current tail(pointer to Node) is newNode
                tail->next = newNode;
                // Change current tail into newNode
                tail = newNode;
            }
            currOther = currOther->next;
        }
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
        Node *curr = head;
        while (curr->next)
            curr = curr->next;

        // Case 2: if last node has space, insert value
        if (curr->numElements < NODE_CAPACITY)
        {
            curr->arr[curr->numElements++] = value;
        }
        else
        {
            // Case 3: if last Node full, split and carry one half to new node
            Node *newNode = new Node();

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
        Node *curr = head;
        Node *prev = nullptr;

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
                    if (curr->numElements == 0)
                    {

                        if (prev == nullptr)
                        {
                            head = curr->next;
                            delete curr;
                        }
                        else
                        {
                            prev->next = curr->next;
                            delete curr;
                        }
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
        Node *curr = head;
        int pos = 0;

        while (curr)
        {
            // Look for value in current(curr) node
            for (int i = 0; i < curr->numElements; ++i)
            {
                if (curr->arr[i] == value)
                    return pos; // found
                ++pos;
            }
            // If not found, move to next node
            curr = curr->next;
        }

        throw ValueNotFound("Exception in UnrolledLinkedList::Impl::find: could not find value");
    }

    int UnrolledLinkedList::Impl::getValue(int index) const
    {
        if (index < 0)
            throw std::out_of_range("Exception in UnrolledLinkedList::Impl::getValue: Negative index not allowed");

        Node *curr = head;

        while (curr)
        {
            if (index < curr->numElements)
                return curr->arr[index];
            index -= curr->numElements;
            curr = curr->next;
        }

        // Out of Bounds exception
        throw std::out_of_range("Exception in UnrolledLinkedList::Impl::getValue: Index out of bounds");
    }

    void UnrolledLinkedList::Impl::edit(int index, int newValue)
    {
        if (index < 0)
            throw std::out_of_range("Exception in UnrolledLinkedList::Impl::edit: Negative index not allowed");

        Node *curr = head;

        while (curr)
        {
            if (index < curr->numElements)
            {
                curr->arr[index] = newValue;
                return;
            }
            index -= curr->numElements;
            curr = curr->next;
        }

        // Out of Bounds exception
        throw std::out_of_range("Exception in UnrolledLinkedList::Impl::edit: Index out of bounds");
    }

    void UnrolledLinkedList::Impl::clear()
    {
        Node *curr = head;

        // Go through each node and delete it
        while (curr)
        {
            Node *tmp = curr;
            curr = curr->next;
            delete tmp; // Node destructor gets called
        }

        head = nullptr;
    }

    int UnrolledLinkedList::Impl::compare(const Impl *other) const
    {
        if (!other)
        {
            // An exception
        }
        Node *a = head;
        Node *b = other->head;

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

    int UnrolledLinkedList::Impl::getSize() const
    {
        int size = 0;
        for (Node *curr = head; curr; curr = curr->next)
            size += curr->numElements;
        return size;
    }

    std::string UnrolledLinkedList::Impl::toString() const
    {
        Node *curr = head;
        std::stringstream ss;
        if (curr)
            ss << "|";
        while (curr)
        {
            ss << curr->numElements << ":";
            for (int i = 0; i < curr->numElements; ++i)
            {
                ss << " " << curr->arr[i];
            }
            ss << "|"; // separator for different nodes
            curr = curr->next;
        }

        return ss.str();
    }

    // UnrolledLinkedList Method Definitions

    UnrolledLinkedList::UnrolledLinkedList()
    {
        pImpl = new Impl();
    }

    UnrolledLinkedList::UnrolledLinkedList(const UnrolledLinkedList &other)
    {
        pImpl = new Impl(*other.pImpl);
    }

    UnrolledLinkedList::~UnrolledLinkedList()
    {
        delete pImpl;
    }

    UnrolledLinkedList &UnrolledLinkedList::operator=(const UnrolledLinkedList &other)
    {
        delete pImpl;
        pImpl = new Impl(*other.pImpl);
        return *this;
    }

    UnrolledLinkedList &UnrolledLinkedList::operator+=(const int value)
    {
        pImpl->insert(value);
        return *this;
    }

    UnrolledLinkedList &UnrolledLinkedList::operator-=(const int value)
    {
        pImpl->remove(value);
        return *this;
    }

    int UnrolledLinkedList::operator[](const int value) const
    {
        return pImpl->find(value);
    }

    int UnrolledLinkedList::at(const int index) const
    {
        return pImpl->getValue(index);
    }

    UnrolledLinkedList &UnrolledLinkedList::operator*=(const std::pair<int, int> pair1)
    {
        pImpl->edit(pair1.first, pair1.second);
        return *this;
    }

    void UnrolledLinkedList::operator!()
    {
        pImpl->clear();
    }

    bool UnrolledLinkedList::operator==(const UnrolledLinkedList &other) const
    {
        return (pImpl->compare(other.pImpl) == 0);
    }

    bool UnrolledLinkedList::operator!=(const UnrolledLinkedList &other) const
    {
        return (pImpl->compare(other.pImpl) != 0);
    }

    bool UnrolledLinkedList::operator<(const UnrolledLinkedList &other) const
    {
        return (pImpl->compare(other.pImpl) == -1);
    }

    bool UnrolledLinkedList::operator<=(const UnrolledLinkedList &other) const
    {
        int result = pImpl->compare(other.pImpl);
        return (result == -1) || (result == 0);
    }

    bool UnrolledLinkedList::operator>(const UnrolledLinkedList &other) const
    {
        return (pImpl->compare(other.pImpl) == 1);
    }

    bool UnrolledLinkedList::operator>=(const UnrolledLinkedList &other) const
    {
        int result = pImpl->compare(other.pImpl);
        return (result == 1) || (result == 0);
    }

    int UnrolledLinkedList::getSize() const
    {
        return pImpl->getSize();
    }

    std::string UnrolledLinkedList::toString() const
    {
        return pImpl->toString();
    }
}
