#include <iostream>
#include <stdexcept>
#include <vector>

class Vector
{
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
            }
            delete[] mem;
            mem = newMem;
            capacity *= 2;
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
        // if (mem == nullptr)
        // {
            delete[] mem;
        // }
    }
    int &operator[](int i)
    {
        return mem[i];
    }

    int *silly(int x)
    {
        return &mem[x];
    }

    int &at(int y){
        if (y>=capacity)
        {
            std::runtime_error("Capacity passed");
        }
        return mem[y];  
    }
    
    Vector(const Vector &original):
    capacity(original.capacity),
    elements(original.elements),
    mem(new int[capacity])
    {
        for (int i = 0; i < capacity; i++)
        {
            mem[i] = original.mem[i];
        }
        
    }
    // int &operator[](int i)
    // {
    //     return mem[i];
    // }
};

int main()
{
    // std::vector<int> xs(10);
    // // xs.push_back(1); // it can be used only where the vector memory is not pre allocated
    // xs.at(0) = 1;
    // xs.at(8) = 34;
    // for (int i = 0; i < 10; i++)
    // {
    //     std::cout << xs[i] << std::endl;
    // }
    std::cout << std::endl;
    
    // xs.at(12) = 34;
    // xs.pop_back();
    Vector x;
    for (int i = 0; i < 100; i++)
    {
        x.push_back(i);
    }
        // x[9] = 9999;
        // x[111] = 13333;
    // x.at(111) = 000000;
    for (int i = 0; i < 112; i++)
    {
        std::cout << x[i] << " ";
    }
    std::cout << std::endl;

    // direct access of the memory
    int *dAMemory = x.silly(95);
    //  dAMemory = x.silly(4);
    std::cout << dAMemory;
    // same start
    // dAMemory[0] = 77777;
    *(dAMemory + 0) = 77777;
    // same end
    *(dAMemory + 1) = 88888;
    for (int i = 0; i < 10; i++)
    {
        std::cout << x.back() << std::endl;
        x.pop_back();
    }
    Vector y(x);
    return 0;
}