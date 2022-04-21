#include <iostream>
#include <stdexcept>

class Stack
{
    int capacity;
    int elements;
    int *mem;

public:
    Stack() : capacity(10),
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

    int top()
    {
        if (empty())
            throw std::runtime_error("It is not possible to read elements from an empty stack");
        return mem[elements - 1];
    }
    void push(int x)
    {
        if (capacity == elements)
        {
            int *newMem = new int[capacity * 2];
            for (int i = 0; i < capacity; i++)
            {
                newMem[i] = mem[i];
            }
            delete[] mem;
            mem = newMem;
            capacity *= 2;
        }

        mem[elements++] = x;
    }
    void pop()
    {
        if (empty())
            throw std::runtime_error("It is not possible to pop elements from an empty stack");
        elements--;
    }

    ~Stack()
    {
        if (mem == nullptr)
        {
            delete[] mem;
        }
    }
};

int main()
{
    return 0;
}