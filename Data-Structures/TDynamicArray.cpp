#include <iostream>
#include <assert.h>
using namespace std;

template <class T>
class DynamicArray
{
private:
    int size_;
    int max_;
    T *arrayHolder_;

public:
    DynamicArray()
    {
        this->size_ = 0;
        this->max_ = 5;
        this->arrayHolder_ = new T[this->max_];
    }

    ~DynamicArray()
    {
        delete[] this->arrayHolder_;
    }

    int getSize()
    {
        return this->size_;
    }

    T &operator[](int index)
    {
        assert(index < this->size_);
        return this->arrayHolder_[index];
    }

    void add(T value)
    {
        if (this->max_ < this->size_ + 1)
        {
            this->max_ *= 2;
            int *tmp = new T[this->max_];
            for (size_t i = 0; i < this->size_; i++)
            {
                tmp[i] = this->arrayHolder_[i];
            }
            delete[] this->arrayHolder_;
            this->arrayHolder_ = tmp;
            this->arrayHolder_[this->size_] = value;
            this->size_ += 1;
        }
        else
        {
            this->arrayHolder_[this->size_] = value;
            this->size_ += 1;
        }
    }
};

int main(int argc, char **argv)
{
    DynamicArray<int> dArray;
    cout << "" << endl;
    cout << "Addding 25 integer in Array" << endl;
    for (size_t i = 0; i < 25; i++)
    {
        dArray.add(i);
    }
    cout << "Last element : " << dArray[24] << endl;
    cout << "Array size_ : " << dArray.getSize() << endl;
    return 0;
}