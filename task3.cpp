#include <iostream>
#include <stdexcept>

class Stack
{
    int size, element;
    int *mem;

public:
    Stack() : size(10), element(0), mem(new int[size])
    {
    }
    void push(int x)
    {
        mem[element++] = x;
    }

    int &operator[](int x)
    {
        return mem[x];
    }
    ~Stack()
    {
        if (mem != nullptr)
        {
            delete[] mem;
        }
    }
    Stack &operator=(const Stack &original)
    {
        if (this != &original)
        {
            if (mem != nullptr)
            {
                // when i build and run then it stuck here
                delete[] mem;
                ////////////////////
            }
            size = original.size;
            element = original.element;
            mem = new int[size];
            for (int i = 0; i < element; i++)
            {
                mem[i] = original.mem[i];
            }
        }
        return *this;
    }
};

int main()
{
    Stack st;
    for (int i = 0; i < 10; i++)
    {
        st.push(i);
    }
    Stack st2;
    for (int i = 0; i < 10; i++)
    {
        st2.push(-i * i);
    }

    st = st2;

    for (int i = 0; i < 10; i++)
    {
        std::cout << i << " :" << st[i] << std::endl;
    }

    return 0;
}