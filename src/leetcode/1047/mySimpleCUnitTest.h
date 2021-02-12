#ifndef _MY_SIMPLE_C_UNIT_TEST_H
#define _MY_SIMPLE_C_UNIT_TEST_H

#include <stdio.h>
#include <stdlib.h>
#include "Solution.h"
#include "SimpleCUnitTestUtil.h"

typedef struct {
    const char **list1; //in
    int list1Size;//in
    const char **list2; //in
    int list2Size;//in
    int returnSize;    //in_out 
} Input_Data_t;

typedef struct {
    char **ans;//out
    int returnSize;//in_out
} Output_Data_t;

typedef struct {
    Input_Data_t input;
    Output_Data_t expected_output;
    Output_Data_t actual_output;
} TestData;

#endif
