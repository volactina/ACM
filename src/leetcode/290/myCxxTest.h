#ifndef __MYCXXTEST_H
#define __MYCXXTEST_H

#include <cxxtest/TestSuite.h>
#include "Solution.h"

class myCxxTest : public CxxTest::TestSuite {
public:
    void test1() {
		char pattern[] = "abba";
		char str[] = "dog cat cat dog";
		bool output = true;
        TS_ASSERT_EQUALS(wordPattern(pattern, str),output);
    }
    void test2() {
		char pattern[] = "abba";
		char str[] = "dog cat cat fish";
		bool output = false;
        TS_ASSERT_EQUALS(wordPattern(pattern, str),output);
    }
    void test3() {
		char pattern[] = "aaaa";
		char str[] = "dog cat cat dog";
		bool output = false;
        TS_ASSERT_EQUALS(wordPattern(pattern, str),output);
    }
    void test4() {
		char pattern[] = "abba";
		char str[] = "dog dog dog dog";
		bool output = false;
        TS_ASSERT_EQUALS(wordPattern(pattern, str),output);
    }
    void test1_uthash() {
		char pattern[] = "abba";
		char str[] = "dog cat cat dog";
		bool output = true;
        TS_ASSERT_EQUALS(wordPattern_uthash(pattern, str),output);
    }
    void test2_uthash() {
		char pattern[] = "abba";
		char str[] = "dog cat cat fish";
		bool output = false;
        TS_ASSERT_EQUALS(wordPattern_uthash(pattern, str),output);
    }
    void test3_uthash() {
		char pattern[] = "aaaa";
		char str[] = "dog cat cat dog";
		bool output = false;
        TS_ASSERT_EQUALS(wordPattern_uthash(pattern, str),output);
    }
    void test4_uthash() {
		char pattern[] = "abba";
		char str[] = "dog dog dog dog";
		bool output = false;
        TS_ASSERT_EQUALS(wordPattern_uthash(pattern, str),output);
    }
};
#endif
