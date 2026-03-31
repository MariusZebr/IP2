template <typename T>
class UnrolledList {
public:
    // Constructors/Destructors
    UnrolledList();
    ~UnrolledList();

    // Insert/Delete
    UnrolledList& operator+=(const T& value);
    UnrolledList& operator-=(const T& value);

    // Search by Value
    int operator[](const T& value) const;

    //void updateAt(int index, const T& value, char op); // update (if meaningful for T)

    // Clear Object
    void operator!();

    // Lexicographical Comparisons of Objects
    bool operator==(const UnrolledList<T>& other) const;
    bool operator!=(const UnrolledList<T>& other) const;
    bool operator< (const UnrolledList<T>& other) const;
    bool operator<=(const UnrolledList<T>& other) const;
    bool operator> (const UnrolledList<T>& other) const;
    bool operator>=(const UnrolledList<T>& other) const;

    std::string toString() const;

private:
    class Impl;
    Impl* pImpl;
};
