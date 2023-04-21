#ifndef DSMODULE_ONELINKEDLIST_CPP
#define DSMODULE_ONELINKEDLIST_CPP

#include "one_linked_list.h"


template <typename DataType>
OneListNode<DataType>::OneListNode(const DataType &value): next(nullptr), data(value) {}
template <typename DataType>
OneListNode<DataType>::OneListNode(DataType &&value) noexcept: data(std::move(value)), next(nullptr) {}
template <typename DataType>
OneListNode<DataType>::~OneListNode() {}

template <typename DataType>
one_linked_list<DataType>::one_linked_list():head(nullptr), tail(nullptr) {}
template <typename DataType>
one_linked_list<DataType>::one_linked_list(std::initializer_list<DataType> data):head(nullptr), tail(nullptr) {
    for (const auto& item : data)
        this->push_back(item);
}

template <typename DataType>
one_linked_list<DataType>::~one_linked_list() {
    while (head) {
        pop_front();
    }
}

template <typename DataType>
OneListNode<DataType>* one_linked_list<DataType>::push_back(const DataType &item) {
    auto new_node = new OneListNode(item);

    if (!head) head = new_node;
    if (tail) tail->next = new_node;

    tail = new_node;

    return new_node;
}
template <typename DataType>
OneListNode<DataType>* one_linked_list<DataType>::push_front(const DataType &item) {
    auto new_node = new OneListNode(item);

    new_node->next = head;

    if (!tail) tail = new_node;

    head = new_node;
    return new_node;
}
template <typename DataType>
int one_linked_list<DataType>::size() {
    auto ptr = head;
    int result = 0;

    for (;ptr != tail;ptr = ptr->next) result++;
    return result == 0 ? 0 : result + 1;
}

template <typename DataType>
bool one_linked_list<DataType>::isEmpty() {
    return size() == 0;
}

template <typename DataType>
DataType one_linked_list<DataType>::pop_back() {
    if (!tail)
        throw new std::exception;

    auto back_data = tail->data;

    auto node = head;

    for (;node->next != tail;node = node->next);

    if (node) node->next = nullptr;
    delete tail;

    tail = node;
    return back_data;
}

template <typename DataType>
DataType one_linked_list<DataType>::pop_front() {
    if (!head)
        throw new std::exception;

    auto front_data = head->data;

    if (head == tail) {
        delete tail;
        head = tail = nullptr;
        return front_data;
    }


    auto node = head;
    head = head->next;

    delete node;
    return front_data;
}


template <typename DataType>
void one_linked_list<DataType>::erase(int index) {
    if (index >= size())
        return;
    auto ptr = head;
    for (int i = 0;i < index;++i) ptr = ptr->next;
}

template <typename DataType>
void one_linked_list<DataType>::displayList() {
    for (auto it = head;it && it != tail; it = it->next)
        std::cout << it->data << "->";
    std::cout << tail->data << std::endl;
}

template <typename DataType>
OneListNode<DataType> *one_linked_list<DataType>::at(int index) {
    if (index >= size() || index < 0)
        throw new std::exception;

    auto node = head;

    for (int i = 0;node && i != index;++i, node = node->next);
    return node;
}

template <typename DataType>
DataType one_linked_list<DataType>::operator[](int index) {
    return at(index)->data;
}

template <typename DataType>
void one_linked_list<DataType>::operator=(one_linked_list<DataType> &&) noexcept {}

#endif