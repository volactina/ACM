#include <stdio.h>
#include "Solution.h"

int main()
{
	char pattern[] = "abba";
	char str[] = "dog cat cat dog";
	printf("%d\n", wordPattern(pattern, str));
	printf("%d\n", wordPattern_uthash(pattern, str));
	return 0;
}
