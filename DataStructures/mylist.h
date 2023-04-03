#ifndef DSMODULE_MYLIST_H
#define DSMODULE_MYLIST_H

#pragma once

#include <algorithm>
#include <iostream>
#include <initializer_list>


namespace MyDss {
    template <typename DataType>
    struct ListNode {
        DataType data;
        ListNode* prev, *next;
        explicit ListNode(DataType&& value) noexcept;
        explicit ListNode(const DataType& value);
        ~ListNode();
    };

    template <typename DataType>
    class MyList {
        ListNode<DataType>* head, *tail;
    public:
        MyList();
        MyList(std::initializer_list<DataType>);
        ~MyList();

        void operator = (MyList<DataType>&&) noexcept ;
        DataType operator [] (int index);

        ListNode<DataType>* push_front(const DataType& item);
        ListNode<DataType>* push_back(const DataType& item);
        bool is_empty();
        size_t size();
        ListNode<DataType>* insert(const DataType& item, int pos);
        DataType pop_back();
        DataType pop_front();
        ListNode<DataType>* at(int index);
        void erase(int index);
        void displayList();
    };

}
#endif
