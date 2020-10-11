#include <stdio.h>
#include "Solution.h"

static bool findInList(const char *s, const char **list, int listSize) 
{
	for (int i = 0; i < listSize; i++) {
		if (strcmp(s, list[i]) == 0) {
			return true;
		}
	}
	return false;
}

int main()
{
	// char *s[]={"Shogun", "Tapioca Express", "Burger King", "KFC"};
	// printf("%s\n", s[0]);
	// printf("%s\n", s[1]);
	const char *list1[] = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
	const char *list2[] = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
	const int list1Size = 4;
	const int list2Size = 4;
	const char *listAns[] = {"Shogun"};
	const int listAnsSize = 1;
	int returnSize;
	char **myAns = findRestaurant(list1, list1Size, list2, list2Size, &returnSize);
	if (returnSize == 0) {
		printf("returnSize should not be 0\n");
	}
	for (int i = 0; i < listAnsSize; i++) {
		if (!findInList(listAns[i], (const char **)myAns, returnSize)) {
			printf("wrong answer\n");
		}
	}
	return 0;
}
