#ifndef __MYCXXTEST_H
#define __MYCXXTEST_H

#include <cxxtest/TestSuite.h>
#include <ctime>
#include "Solution.h"

using namespace std;

class SimpleTest : public CxxTest::TestSuite {
public:
    void test1() {
        int input = 10;
        int output = 4;
        TS_ASSERT_EQUALS(countPrimes(input), output);
    }
    void test2() {
        int input = 0;
        int output = 0;
        TS_ASSERT_EQUALS(countPrimes(input), output);
    }
    void test3() {
        int input = 1;
        int output = 0;
        TS_ASSERT_EQUALS(countPrimes(input), output);
    }
    void test4() {
        clock_t time_start = clock();
        countPrimes(500000);
        clock_t time_end = clock();
        int time_consumed = 1000 * (time_end - time_start) / (double)CLOCKS_PER_SEC;
        cout << "time consumed:" << time_consumed << "ms" << endl;
    }
};
#endif
