#ifndef __MYCXXTEST_H
#define __MYCXXTEST_H

#include <cxxtest/TestSuite.h>
#include <ctime>
#include "Solution.h"

using namespace std;

class SimpleTest : public CxxTest::TestSuite {
public:
    void test1() {
        char *list1[] = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
        char *list2[] = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
        int list1Size = 4;
        int list2Size = 4;
        char *listAns[] = {"Shogun"};
        int listAnsSize = 1;
        int returnSize;
        char **myAns = findRestaurant(list1, list1Size, list2, list2Size, &returnSize);
        if (returnSize == 0) {
            TS_FAIL("returnSize should not be 0");
        }
        for (int i = 0; i < listAnsSize; i++) {
            if (!findInList(listAns[i], myAns, returnSize)) {
                TS_FAIL("wrong answer");
            }
        }
    }
private:
    bool findInList(const char *s, const char **list, int listSize) {
        for (int i = 0; i < listSize; i++) {
            if (strcmp(s, list[i]) == 0) {
                return true;
            }
        }
        return false;
    }
};
#endif