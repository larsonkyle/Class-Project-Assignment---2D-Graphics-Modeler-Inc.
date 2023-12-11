#ifndef VECTOR_DOUBLES_H_
#define VECTOR_DOUBLES_H_
#include <algorithm> // std::copy
using std::copy;

namespace myStd
{
template <typename T>
class vector
{
    int size_v;    // the size
    T *elem;  // pointer to the elements (or 0)
    int space;     // number of elements plus number of free slots

public:
    vector() : size_v{0}, elem{nullptr}, space{0} {} // default constructor
    explicit vector(int s) : size_v{s}, elem{new T[s]}, space{s} // alternate constructor
    {
        for (int i = 0; i < size_v; ++i)
            elem[i] = T(); // elements are initialized
    }

    vector(const vector &src) : size_v{src.size_v}, elem{new T[src.size_v]}, space{src.space} // copy constructor
    {
        copy(src.elem, src.elem + size_v, elem); // copy elements - std::copy() algorithm
    }

    vector &operator=(const vector &src) // copy assignment
    {
        T *p = new T[src.size_v]; // allocate new space
        copy(src.elem, src.elem + src.size_v, p); // copy elements - std::copy() algorithm
        delete[] elem; // deallocate old space
        elem = p; // now we can reset elem
        size_v = src.size_v;
        space = src.size_v; // Update space to match the new size
        return *this; // return a self-reference
    }

    ~vector()
    {
        delete[] elem; // destructor
    }

    T &operator[](int n)
    {
        return elem[n]; // access: return reference
    }

    const T &operator[](int n) const
    {
        return elem[n];
    }

    int size() const
    {
        return size_v;
    }

    int capacity() const
    {
        return space;
    }

    void resize(int newsize) // growth
    {
        reserve(newsize);
        for (int i = size_v; i < newsize; ++i)
            elem[i] = T(); // initialize new elements
        size_v = newsize;
    }

    void push_back(T d)
    {
        if (space == 0)
            reserve(8); // start with space for 8 elements
        else if (size_v == space)
            reserve(2 * space); // get more space
        elem[size_v] = d; // add d at the end
        ++size_v; // increase the size
    }

    void reserve(int newalloc)
    {
        if (newalloc <= space)
            return; // Never decrease allocation
        T *p = new T[newalloc]; // Allocate new space
        copy(elem, elem + size_v, p); // Copy old elements
        delete[] elem; // Deallocate old space
        elem = p; // Update elem to point to the new memory
        space = newalloc; // Update space to match the new allocation
    }

    using iterator = T*;
    using const_iterator = const T*;

    iterator begin()
    {
        if (size_v == 0)
            return nullptr;
        return &elem[0];
    }

    const_iterator begin() const
    {
        if (size_v == 0)
            return nullptr;
        return &elem[0];
    }

    iterator end()
    {
        if (size_v == 0)
            return nullptr;
        return &elem[size_v];
    }

    const_iterator end() const
    {
        if (size_v == 0)
            return nullptr;
        return &elem[size_v];
    }

    iterator insert(iterator p, const double &val)
    {
        if (size_v == space)
            reserve(space == 0 ? 8 : 2 * space); // Ensure enough space

        int index = p - begin(); // Calculate the index for the iterator

        p = begin() + index; // Recalculate p in case the vector was reallocated

        for (iterator pos = end(); pos != p; --pos)
            *(pos) = *(pos - 1); // Shift elements one position to the right

        *p = val;
        ++size_v; // Increase the size

        return nullptr;
    }


    iterator erase(iterator p)
    {
        if (p == end())
            return p;

        for (iterator pos = p; pos != end() - 1; ++pos)
            *(pos) = *(pos + 1); // Shift elements one position to the left

        --size_v; // Decrease the size

        return p;
    }
};
}

#endif /* VECTOR_H_ */
