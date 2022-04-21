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
    Vector() : capacity(10),
               elements(0),
               mem(new int[capacity])
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
        if (capacity == elements)
        {
            int *newMem = new int[capacity * 2];
            for (int i = 0; i < capacity; i++)
            {
                newMem[i] = mem[i];
                // std::cout<<newMem[i]<<" "<<mem[i]<<" ";
            }
            delete[] mem;
            mem = newMem;
            capacity += 1;
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
        if (mem == nullptr)
        {
            delete[] mem;
        }
    }
    int &operator[](int i)
    {
        return mem[i];
    }
};

int main()
{
    Vector alpha;
    for (int i = 0; i < 1000000; i++)
    {
        alpha.push_back(i * i);
    }
    for (int i = 0; i < 1000000; i++)
    {
        std::cout << alpha[i] << std::endl;
    }

    return 0;
}