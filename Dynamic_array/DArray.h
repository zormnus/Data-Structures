#ifndef DSMODULE_DARRAY_H
#define DSMODULE_DARRAY_H

#include <initializer_list>
#include <iostream>
#include <algorithm>

template <typename DataType>
class DArray {
private:
    const int capacity_k = 2;
    int capacity_;
    DataType* data_;
    int size_;
    void expand();
    void reduce();
public:
    explicit DArray();
    DArray(const DArray<DataType>& other);
    explicit DArray(int n, DataType value);
    explicit DArray(std::initializer_list<DataType> data);
    ~DArray();

    DArray<DataType> operator = (const DArray<DataType>& other) noexcept;
    bool operator == (const DArray<DataType>& other) noexcept;
    DataType operator [] (int position) noexcept;

    void push_front(const DataType& item);
    void push_back(const DataType& item);
    void insert(int position, const DataType& item);
    DataType pop_back();
    DataType pop_front();
    void erase(int position);

    bool is_empty();
    int get_size();
    int get_capacity();

    void displayArray();
};
#include "DArray.cpp"
#endif