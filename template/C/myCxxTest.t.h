#ifndef __MYCXXTEST_H
#define __MYCXXTEST_H

#include <cxxtest/TestSuite.h>
#include <ctime>
#include "Solution.h"

using namespace std;

class SimpleTest : public CxxTest::TestSuite {
public:
    void testEquality() {
        hello();
        TS_ASSERT_EQUALS(1,1);
    }
	void testTimeCost() {
        clock_t time_start = clock();
		//Solution run here
        clock_t time_end = clock();
        int time_consumed = 1000 * (time_end - time_start) / (double)CLOCKS_PER_SEC;
        cout << "time consumed:" << time_consumed << "ms" << endl;
    }
private:
    void hello() {
        cout << endl << "hello" << endl;
    }
    void generate_input() {
        //
    }
    void check_output() {
        //
    }
};
#endif