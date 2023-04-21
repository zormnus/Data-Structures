#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK

#include "Dynamic_array/DArray.h"
#include "One-linked_list/one_linked_list.h"
#include "Two-linked_list/two_linked_list.h"

#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_SUITE(DArray_tests)
BOOST_AUTO_TEST_CASE(PUSH_FRONT) {

    DArray<int> array;
    array.push_front(1);
    array.push_front(2);

    DArray<int> comp{2,1};

    BOOST_REQUIRE_EQUAL(array == comp, true);
}

BOOST_AUTO_TEST_CASE(PUSH_BACK) {
    DArray<int> array;
    array.push_back(1);
    array.push_back(2);

    DArray<int> comp{1, 2};
    BOOST_REQUIRE_EQUAL(array == comp, true);
}

BOOST_AUTO_TEST_CASE(SIZE_TEST) {
    DArray<int> array {5,1,2};
    BOOST_REQUIRE_EQUAL(array.get_size() == 3, true);
}

BOOST_AUTO_TEST_CASE(FALSECOMPARE) {
    DArray<std::string> array{"Hello", "World!"};
    DArray<std::string> comp{"Adam"};
    BOOST_REQUIRE_EQUAL(array == comp, false);
}

BOOST_AUTO_TEST_CASE(INSERT) {
    DArray<std::string> array;

    for (int i = 0; i < 100; ++i) {
        array.insert(i, "Hello");
    }

    DArray<std::string> comp(100, "Hello");
    BOOST_REQUIRE_EQUAL(array == comp, true);
}

BOOST_AUTO_TEST_CASE(POPBACK) {

    DArray<int> array{1,2,3,4,5,6,7,8};

    for (int i = 0; i < 4; ++i)
        array.pop_back();

    DArray<int> comp{1,2,3,4};
    BOOST_REQUIRE_EQUAL(array == comp, true);
    BOOST_REQUIRE_EQUAL(array.get_capacity() == 8, true);
}

BOOST_AUTO_TEST_CASE(POPFRONT) {
    DArray<int> array{1,2,3,4,5,6,7,8};

    for (int i = 0; i < 4; ++i)
        array.pop_front();

    DArray<int> comp{5,6,7,8};
    BOOST_REQUIRE_EQUAL(array == comp, true);
    BOOST_REQUIRE_EQUAL(array.get_capacity() == 8, true);
}

BOOST_AUTO_TEST_CASE(ERASE) {
    DArray<std::string> array{"Hello!", "erase me!!!"};

    DArray<std::string> array2{"Value1", "Value2", "Value3"};

    array.erase(1);

    array2.erase(0);

    DArray<std::string> comp{"Hello!"};
    DArray<std::string> comp2{"Value2", "Value3"};

    BOOST_REQUIRE_EQUAL(array == comp, true);
    BOOST_REQUIRE_EQUAL(array2 == comp2, true);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(OneLinkedList_tests)

BOOST_AUTO_TEST_CASE(PUSHBACK) {
    DArray<int> array;

    array.push_back(1);

    array.push_back(2);

    DArray<int> comp{1,2};

    BOOST_REQUIRE_EQUAL(array == comp, true);
}

BOOST_AUTO_TEST_CASE(PUSHFRONT_POP) {
        DArray<int> array;

        array.push_front(1);

        array.push_front(2);

        DArray<int> comp{2,1};

        BOOST_REQUIRE_EQUAL(array == comp, true);

        array.pop_front();

        DArray<int> comp1{1};

        BOOST_REQUIRE_EQUAL(array == comp1, true);
}

BOOST_AUTO_TEST_SUITE_END()