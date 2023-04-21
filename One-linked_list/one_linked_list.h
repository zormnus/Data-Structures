#ifndef DSMODULE_ONELINKEDLIST_H
#define DSMODULE_ONELINKEDLIST_H

#include <algorithm>
#include <iostream>

template <typename DataType>
struct OneListNode {
    DataType data;
    OneListNode* next;
    explicit OneListNode(DataType&& value) noexcept;
    explicit OneListNode(const DataType& value);
    ~OneListNode();
};
template <typename DataType>
class one_linked_list {
    OneListNode<DataType>* head, *tail;
public:
    one_linked_list(std::initializer_list<DataType> data);
    one_linked_list();
    ~one_linked_list();

    OneListNode<DataType>* push_back(const DataType& item);
    OneListNode<DataType>* push_front(const DataType& item);
    DataType pop_front();
    DataType pop_back();

    void erase(int index);
    int size();
    bool isEmpty();

    DataType operator [] (int index);
    void operator = (one_linked_list<DataType>&&) noexcept;

    OneListNode<DataType>* at(int index);
    void displayList();
};
#include "one_linked_list.cpp"
#endif