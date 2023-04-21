#ifndef DSMODULE_TWOLINKEDLIST_H
#define DSMODULE_TWOLINKEDLIST_H

#include <algorithm>
#include <iostream>
#include <initializer_list>


template <typename DataType>
struct TwoListNode {
    DataType data;
    TwoListNode* prev, *next;
    explicit TwoListNode(DataType&& value) noexcept;
    explicit TwoListNode(const DataType& value);
    ~TwoListNode();
};

template <typename DataType>
class two_linked_list {
    TwoListNode<DataType>* head, *tail;
public:
    two_linked_list();
    two_linked_list(std::initializer_list<DataType>);
    ~two_linked_list();

    void operator = (two_linked_list<DataType>&&) noexcept ;
    DataType operator [] (int index);

    TwoListNode<DataType>* push_front(const DataType& item);
    TwoListNode<DataType>* push_back(const DataType& item);
    bool is_empty();
    size_t size();
    TwoListNode<DataType>* insert(const DataType& item, int pos);
    DataType pop_back();
    DataType pop_front();
    TwoListNode<DataType>* at(int index);
    void erase(int index);
    void displayList();
};
#include "two_linked_list.cpp"
#endif