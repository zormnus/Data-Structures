#ifndef DSMODULE_DARRAY_CPP
#define DSMODULE_DARRAY_CPP

#include "DArray.h"


template <typename DataType>
void DArray<DataType>::expand() {
    DataType* copy_obj = new DataType[size_ * capacity_k];

    for (int i = 0; i < size_; ++i)
        copy_obj[i] = data_[i];

    delete[] data_;
    data_ = copy_obj;
    capacity_ *= capacity_k;
}

template <typename DataType>
void DArray<DataType>::reduce() {
    DataType* copy_obj = new DataType[static_cast<int>(capacity_ / 2)];

    for (int i = 0; i < size_; ++i)
        copy_obj[i] = data_[i];

    delete[] data_;

    data_ = copy_obj;
    capacity_ /= 2;
}

template <typename DataType>
DArray<DataType>::DArray(const DArray<DataType> &other) {}

template <typename DataType>
void DArray<DataType>::push_back(const DataType &item) {
    if (size_ == capacity_)
        expand();
    data_[size_++] = item;
}

template <typename DataType>
void DArray<DataType>::erase(int position) {
    if (position < 0 || position >= size_)
        throw std::out_of_range("Index is out of range");
    for (int i = position; i < size_ - 1; ++i)
        std::swap(data_[i], data_[i + 1]);
    size_--;

    if (capacity_ / size_ >= 4)
        reduce();
}


template <typename DataType>
void DArray<DataType>::insert(int position, const DataType& item) {
    if (position < 0 || position > size_)
        throw std::out_of_range("Index is out of range");
    if (size_ == capacity_)
        expand();
    for (int i = size_; i > position; --i)
        std::swap(data_[i], data_[i - 1]);
    data_[position] = item;
    size_++;
}



template <typename DataType>
void DArray<DataType>::push_front(const DataType &item) {
    if (size_ == capacity_)
        expand();
    for (int i = size_ - 1; i >= 0; --i)
        std::swap(data_[i + 1], data_[i]);
    data_[0] = item;
    size_++;
}


template <typename DataType>
DArray<DataType>::DArray(int n, DataType value) {
    size_ = n;
    capacity_ = size_ * capacity_k;
    data_ = new DataType[n];
    for (int i = 0; i < n; ++i) {
        data_[i] = value;
    }
}

template <typename DataType>
DArray<DataType>::DArray(std::initializer_list<DataType> data) {
    this->data_ = new DataType[data.size() * capacity_k];
    size_ = data.size();
    capacity_ = data.size() * capacity_k;

    auto iter = data.begin();
    for (int i = 0; i < data.size(); ++i, iter = std::next(iter)) {
        this->data_[i] = *iter;
    }
}

template <typename DataType>
DArray<DataType>::DArray() {
    data_ = new DataType[2];
    capacity_ = 2;
    size_ = 0;
}


template <typename DataType>
DArray<DataType>::~DArray() {
    delete[] data_;
}


template <typename DataType>
void DArray<DataType>::displayArray() {
    for (int i = 0; i < size_; ++i)
        std::cout << data_[i] << ' ';
    std::cout << std::endl;
}


template <typename DataType>
bool DArray<DataType>::is_empty() {
    return get_size() == 0;
}


template <typename DataType>
int DArray<DataType>::get_size() {
    return size_;
}

template <typename DataType>
int DArray<DataType>::get_capacity() {
    return capacity_;
}


template <typename DataType>
DataType DArray<DataType>::pop_back() {
    if (!size_)
        throw std::out_of_range("Array is empty");
    size_--;
    DataType result = data_[size_];
    if (capacity_ / size_ >= 4)
        reduce();
    return result;
}


template <typename DataType>
DataType DArray<DataType>::pop_front() {
    if (!size_)
        throw std::out_of_range("Array is empty");
    for (int i = 0; i < size_ - 1; ++i)
        std::swap(data_[i], data_[i + 1]);
    return pop_back();
}


template <typename DataType>
DArray<DataType> DArray<DataType>::operator=(const DArray<DataType> &other) noexcept {
    if (this != &other) {
        delete[] data_;
        capacity_ = other.size_ * capacity_k;
        data_ = new DataType[capacity_];
        for (int i = 0; i < other.size_; ++i)
            data_[i] = other[i];
    }
}

template <typename DataType>
DataType DArray<DataType>::operator[](int position) noexcept {
    return data_[position];
}

template <typename DataType>
bool DArray<DataType>::operator==(const DArray<DataType> &other) noexcept {
    if (size_ != other.size_)
        return false;
    for (int i = 0; i < size_; ++i) {
        if (data_[i] != other.data_[i])
            return false;
    }
    return true;
}


#endif