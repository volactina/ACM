#include "mySimpleCUnitTest.h"

static void test1()
{
    const char *list1[] = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
	const char *list2[] = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
	const int list1Size = 4;
	const int list2Size = 4;
	const char *listAns[] = {"Shogun"};
	const int listAnsSize = 1;
	int returnSize;
	char **myAns = findRestaurant(list1, list1Size, list2, list2Size, &returnSize);
	if (returnSize != listAnsSize) {
		printf("!!!returnSize wrong\n");
        return;
	}
	for (int i = 0; i < listAnsSize; i++) {
		if (!findInList(listAns[i], (const char **)myAns, returnSize)) {
			printf("!!!wrong answer!!!\n");
            return;
		}
	}
    printf("pass test1\n");
}

static void test2()
{
    const char *list1[] = {"Shogun","Tapioca Express","Burger King","KFC"};
	const char *list2[] = {"KNN","KFC","Burger King","Tapioca Express","Shogun"};
	const int list1Size = 4;
	const int list2Size = 5;
	const char *listAns[] = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
	const int listAnsSize = 4;
	int returnSize;
	char **myAns = findRestaurant(list1, list1Size, list2, list2Size, &returnSize);
	if (returnSize != listAnsSize) {
		printf("!!!returnSize wrong\n");
        return;
	}
	for (int i = 0; i < listAnsSize; i++) {
		if (!findInList(listAns[i], (const char **)myAns, returnSize)) {
			printf("!!!wrong answer!!!\n");
            return;
		}
	}
    printf("pass test2\n");
}

int main()
{
    test1();
    test2();
}

// static void get_input_data(Input_Data_t *input)
// {
//     const char *list1[] = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
//     const char *list2[] = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
//     const int list1Size = 4;
//     const int list2Size = 4;
//     input->list1 = list1;
//     input->list2 = list2;
//     input->list1Size = list1Size;
//     input->list2Size = list2Size;
// }

// static void get_expected_output_data(Output_Data_t *output)
// {
//     const char *listAns[] = {"Shogun"};
// 	int listAnsSize = 1;
//     output->ans = listAns;
//     output->returnSize = listAnsSize;
// }

// static void check_output(Output_Data_t *actual_output, Output_Data_t *expected_output)
// {
//     if (actual_output->returnSize != expected_output->returnSize) {
// 		printf("returnSize error\n");
// 	}
// 	for (int i = 0; i < expected_output->returnSize; i++) {
// 		if (!findInList(expected_output->ans[i], (const char **)actual_output->ans, actual_output->returnSize)) {
// 			printf("wrong answer\n");
// 		}
// 	}
// }

// static void test_end(TestData *testdata)
// {
//     for(int i = 0;i < testdata->actual_output.returnSize; i++) {
//         free((testdata->actual_output.ans)[i]);
//     }
//     free(testdata->actual_output.ans);
// }

// int main()
// {
//     //test start
//     TestData testdata;
//     //input
//     get_input_data(&(testdata.input));
//     //get actual output
// 	char **myAns = findRestaurant(testdata.input.list1, testdata.input.list1Size,
//                                   testdata.input.list2, testdata.input.list2Size, &(testdata.input.returnSize));
//     testdata.actual_output.ans = myAns;
//     testdata.actual_output.returnSize = testdata.input.returnSize;
//     //expected output
// 	get_expected_output_data(&(testdata.expected_output));
//     //check if actual output fits expected output
// 	check_output(&(testdata.actual_output), &(testdata.expected_output));
//     //release memory used in this test framwork
//     test_end(&testdata);
//     return EXIT_SUCCESS;
// }