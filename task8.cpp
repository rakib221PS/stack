#include <iostream>
#include <stdexcept>
#include <vector>

class Vector
{
public:
    int capacity;
    int elements;
    int *mem;

public:
    Vector() : capacity(0),
               elements(0),
               //    mem(new int[capacity])
               mem(nullptr)
    {
    }

    bool empty()
    {
        if (elements == 0)
        {
            return true;
        }
        return false;
    }

    int back()
    {
        if (empty())
            throw std::runtime_error("It is not possible to read elements from an empty Vector");
        return mem[elements - 1];
    }
    void push_back(int x)
    {
        if (capacity == 0)
        {
            capacity = 2;
            mem = new int[capacity];
        }

        else if (capacity == elements)
        {                                     // 1.
            int *tmp = new int[capacity * 2]; // 1.1.

            // 1.2
            for (int i = 0; i < capacity; i++)
            {
                tmp[i] = mem[i];
            }

            delete[] mem;  // 1.3
            mem = tmp;     // 1.4
            capacity *= 2; // 1.5
        }
        mem[elements++] = x;
    }
    void pop_back()
    {
        if (empty())
            throw std::runtime_error("It is not possible to pop elements from an empty Vector");
        elements--;
    }
    ~Vector()
    {
        if (mem != nullptr)
        {
            delete[] mem;
        }
    }
    int &operator[](int i)
    {
        return mem[i];
    }
    Vector &operator=(const Vector &original)
    {
        if (this != &original)
        {
            if (mem != nullptr)
            {
                // when i build and run then it stuck here
                delete[] mem;
                ////////////////////
            }
            capacity = original.capacity;
            elements = original.elements;
            mem = new int[capacity];
            for (int i = 0; i < elements; i++)
            {
                mem[i] = original.mem[i];
            }
        }
        return *this;
    }
};

int main()
{
    Vector alpha;
    for (int i = 0; i < 3; i++)
    {
        alpha.push_back(i * i);
    }
    for (int i = 0; i < 3; i++)
    {
        std::cout << alpha[i] << std::endl;
    }
    std::cout << "-------------------------" << std::endl;

    Vector v;
    v.push_back(1);
    v = alpha;
    for (int i = 0; i < v.capacity; i++)
    {
        std::cout << v[i] << " ";
    }
    return 0;
}