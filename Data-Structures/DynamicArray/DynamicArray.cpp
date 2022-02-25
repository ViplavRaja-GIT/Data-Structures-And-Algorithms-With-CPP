#include "DynamicArray.h"

template <typename T>
DynamicArray<T>::DynamicArray()
{
    this->size_ = 0;
    this->max_ = 5;
    this->arrayHolder_ = new T[this->max_];
}

template <typename T>
DynamicArray<T>::~DynamicArray()
{
    delete[] this->arrayHolder_;
}

template <typename T>
int DynamicArray<T>::getSize()
{
    return this->size_;
}
template <typename T>
T& DynamicArray<T>::operator[](int index)
{
    assert(index < this->size_);
    return this->arrayHolder_[index];
}

template <typename T>
void DynamicArray<T>:: add(T value)
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

template <typename T>
void DynamicArray<T>:: print()
{
    for (size_t i = 0; i < this->size_; i++)
    {
        cout << " | " << this->arrayHolder_[i];
    }
    cout << " |" << endl;
}