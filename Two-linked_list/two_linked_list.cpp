#ifndef DSMODULE_TWOLINKEDLIST_CPP
#define DSMODULE_TWOLINKEDLIST_CPP

#include "two_linked_list.h"

template <typename DataType>
TwoListNode<DataType>::TwoListNode(DataType&& value) noexcept:
        data(std::move(value)), prev(nullptr), next(nullptr) {}
template <typename DataType>
TwoListNode<DataType>::TwoListNode(const DataType &value):
        data(value), prev(nullptr), next(nullptr) {}
template <typename DataType>
TwoListNode<DataType>::~TwoListNode() {}
template <typename DataType>
two_linked_list<DataType>::two_linked_list(std::initializer_list<DataType> values):head(nullptr), tail(nullptr) {
    head = nullptr;
    tail = nullptr;
    for (const auto& item : values)
        this->push_back(item);
}
template <typename DataType>
two_linked_list<DataType>::two_linked_list(): head(nullptr), tail(nullptr) {}
template <typename DataType>
TwoListNode<DataType> *two_linked_list<DataType>::push_front(const DataType& item) {
    auto new_node = new TwoListNode<DataType>(item);
    new_node->next = head;

    if (head) head->prev = new_node;

    if (!tail) tail = new_node;

    head = new_node;
    return new_node;
}

template <typename DataType>
TwoListNode<DataType> *two_linked_list<DataType>::push_back(const DataType &item) {
    auto new_node = new TwoListNode<DataType>(item);
    new_node->prev = tail;

    if (tail) tail->next = new_node;
    if (!head) head = new_node;

    tail = new_node;
    return new_node;
}

template <typename DataType>
bool two_linked_list<DataType>::is_empty() {
    return !head;
}
template <typename DataType>
size_t two_linked_list<DataType>::size() {
    size_t size;
    for (auto pNode = this->head; pNode; pNode = pNode->next, size++);
    return size;
}
template <typename DataType>
TwoListNode<DataType> *two_linked_list<DataType>::insert(const DataType &item, int pos) {
    if (pos < 0 || pos >= size())
        throw new std::exception;

    TwoListNode<DataType>* right = at(pos);

    if (!right) return push_back(item);

    TwoListNode<DataType>* left = right->prev;

    if (!left) return push_front(item);

    auto new_node = new TwoListNode<DataType>(item);

    new_node->prev = left;
    new_node->next = right;

    left->next = new_node;
    right->prev = new_node;

    return new_node;
}
template <typename DataType>
DataType two_linked_list<DataType>::pop_back() {
    if (!tail)
        throw new std::exception;

    auto back_data = tail->data;
    auto node = tail->prev;

    if (node) node->next = nullptr;
    else head = nullptr;

    delete tail;
    tail = node;
    return back_data;
}
template <typename DataType>
DataType two_linked_list<DataType>::pop_front() {
    if (!head)
        throw new std::exception;

    auto front_data = head->data;
    auto node = head->next;
    if (node) node->prev = nullptr;
    else tail = nullptr;

    delete head;
    head = node;
    return front_data;
}
template <typename DataType>
TwoListNode<DataType>* two_linked_list<DataType>::at(int index) {
    if (index >= this->size() || index < 0)
        throw new std::exception;

    auto node = head;
    for (int i = 0;node && i != index; ++i, node = node->next);
    return node;
}

template <typename DataType>
two_linked_list<DataType>::~two_linked_list() {
    while (head) pop_front();
}

template <typename DataType>
DataType two_linked_list<DataType>::operator[](int index) {
    return at(index)->data;
}
template <typename DataType>
void two_linked_list<DataType>::operator=(two_linked_list<DataType> &&) noexcept {}
template <typename DataType>
void two_linked_list<DataType>::erase(int index) {
    auto node = at(index);

    if (!node) return;

    if (!node->prev) {
        pop_front();
        return;
    }

    if (!node->next) {
        pop_back();
        return;
    }

    auto left = node->prev;
    auto right = node->next;

    left->next = right;
    right->prev = left;

    delete node;
}
template <typename DataType>
void two_linked_list<DataType>::displayList() {
    for (auto it = head;it && it != tail;it = it->next) {
        std::cout << it->data << "->";
    }
    std::cout << tail->data << std::endl;
}

#endif