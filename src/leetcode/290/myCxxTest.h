#ifndef __MYCXXTEST_H
#define __MYCXXTEST_H

#include <cxxtest/TestSuite.h>
#include "Solution.h"

class SimpleTest : public CxxTest::TestSuite {
public:
    void testEquality() {
		char pattern[] = "abba";
		char str[] = "dog cat cat dog";
		bool output = true;
        TS_ASSERT_EQUALS(wordPattern(pattern, str),output);
    }
};
#endif
