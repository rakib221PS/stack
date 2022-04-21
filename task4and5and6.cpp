#include <iostream>
#include <vector>

struct Vector
{
    int size;
    int elements;
    int *mem;
    Vector() : size(3), elements(0), mem(new int[size])
    {
    }

	Vector(int n):size(n), elements(0), mem(new int[size]) { }

	Vector(int n, int x):size(n), elements(0), mem(new int[size]) {
		for (int i = 0 ; i < n ; i++) {
			mem[i] = x;
		}
	}


	void push_back(int x) {
		if (size == elements) {
			int *tmp = new int[size * 2];
			for (int i = 0 ; i < size ; i++) {
				tmp[i] = mem[i];
			}
			delete [] mem;
			mem = tmp;
			size *= 2;
		}
		mem[elements++] = x;
	}


    Vector operator+(const Vector &newVector)
    {
		Vector ret(*this);
        for (int i = 0; i < newVector.elements; i++)
        {
            ret.push_back(newVector.mem[i]);
        }
		return ret; // if You return a copy and You dynamically allocate memory You need a copy constructor and a destructor.
    }

	~Vector() {
		delete [] mem;
	}

	Vector(const Vector &other):
		size(other.size),
		elements(other.elements),
		mem(new int[size])
	{
		for (int i = 0 ; i < size ; i++) {
			mem[i] = other.mem[i];
		}
	}
};

std::ostream &operator<<(std::ostream &o, const Vector &v)
{
	for (int i = 0; i < v.elements; i++)
	{
		o << v.mem[i] << ", ";
	}
	o << std::endl;
	return o;
}


int main()
{
	Vector v;
    for (int i = 0; i < 10; i++)
    {
		v.push_back(i);
    }

    Vector v1;
    for (int i = 0; i < 10; i++)
    {
		v1.push_back(-2 * i);
    }

    std::cout<<&v<<" "<<&v1<<std::endl;
    std::cout << v + v1 << std::endl;
    return 0;
}
