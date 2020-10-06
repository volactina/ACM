#ifndef __MYCXXTEST_H
#define __MYCXXTEST_H

#include <cxxtest/TestSuite.h>
#include "Solution.h"

class SimpleTest : public CxxTest::TestSuite {
public:
    void testEquality() {
        TS_ASSERT_EQUALS(1,1);
    }
};
#endif
