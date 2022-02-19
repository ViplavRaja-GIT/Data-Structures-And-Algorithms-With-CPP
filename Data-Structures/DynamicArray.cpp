#include <iostream>
#include <assert.h>
using namespace std;
class DynamicArray
{
private:
    int size;
    int max;
    int *arrayHolder;

public:
    DynamicArray()
    {
        this->size = 0;
        this->max = 5;
        this->arrayHolder = new int[this->max];
    }

    ~DynamicArray()
    {
        delete[] this->arrayHolder;
    }

    int getSize()
    {
        return this->size;
    }

    int &operator[](int index)
    {
        assert(index < this->size);
        return this->arrayHolder[index];
    }

    void add(int number)
    {
        if (this->max < this->size + 1)
        {
            this->max *= 2;
            int *tmp = new int[this->max];
            for (size_t i = 0; i < this->size; i++)
            {
                tmp[i] = this->arrayHolder[i];
            }
            delete[] this->arrayHolder;
            this->arrayHolder = tmp;
            this->arrayHolder[this->size] = number;
            this->size += 1;
        }
        else
        {
            this->arrayHolder[this->size] = number;
            this->size += 1;
        }
    }
};

int main(int argc, char **argv)
{
    DynamicArray dArray;
    cout << "Addding 20 elements in Array" << endl;
    for (size_t i = 0; i < 20; i++)
    {
        dArray.add(i);
    }
    cout << "Last element : " << dArray[19] << endl;
    cout << "Array Size : " << dArray.getSize() << endl;
    return 0;
}