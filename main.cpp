#include "DataStructures/mylist.cpp"

int main() {
    using namespace MyDss;

    auto list = new MyList<std::string> {"my", "two-linked"};

    list->push_back("list");

    list->displayList();

    list->pop_back();

    list->displayList();

    list->pop_front();

    list->displayList();

    delete list;
    return 0;
}