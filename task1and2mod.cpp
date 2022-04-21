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
        if (mem != nullptr)
        {
            delete[] mem;
        }
    }
    int &operator[](int i)
    {
        return mem[i];
    }

    int *silly(int x)
    {
        return &mem[x];
    }

    int &at(int y)
    {
        if (y <= 10 && y >= 0)
        {
            return mem[y];
        }
        throw std::runtime_error("Capacity passed");
    }

    Vector(const Vector &original) : capacity(original.capacity),
                                     elements(original.elements),
                                     mem(new int[original.capacity])
    {
        for (int i = 0; i < capacity; i++)
        {
            mem[i] = original.mem[i];
        }
    }

    Vector &operator=(const Vector &original)
    {
        if (this != &original)
        { // guard against self assignment
            if (mem != nullptr)
                delete[] mem;             // if mem is allocated, delete it
            capacity = original.capacity; // copy fields from the original
            elements = original.elements; // copy fields from the original
            mem = new int[capacity];      // allocate a new array
            for (int i = 0; i < elements; i++)
            { // copy mem element by element from original
                mem[i] = original.mem[i];
            }
        }
        return *this; // always return a reference
    }
};

int main()
{
    Vector alpha;
    for (int i = 0; i < 10; i++)
    {
        alpha.push_back(i * i);
    }
    Vector beta;
    for (int i = 0; i < 10; i++)
    {
        beta.push_back(-i * i);
    }
    // for (int i = 0; i < 20; i++)
    // {
    //     std::cout<<alpha.mem[i]<<std::endl;
    // }

    // Vector v(beta);
    // std::cout<<&v<<"+"<<&v.mem<<" "<<&beta<<"+"<<&beta.mem<<std::endl;
    // for (int i = 0; i < v.capacity; i++)
    // {
    //     std::cout<<v[i]<<" "<<beta.mem[i]<<std::endl;
    // }
    std::cout<<"-------------------------"<<std::endl;
    std::cout<<&alpha<<"+"<<&alpha.mem[0]<<" "<<&beta<<"+"<<&beta.mem[0]<<std::endl;
    for (int i = 0; i < alpha.capacity; i++)
    {
        std::cout<<alpha[i]<<" "<<beta.mem[i]<<std::endl;
    }
    
    
    alpha = beta;
    for (int i = 0; i < alpha.capacity; i++)
    {
        std::cout<<alpha[i]<<" "<<beta.mem[i]<<std::endl;
    }
    

    // std::cout << alpha.at(78);
    return 0;
}