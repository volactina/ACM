#include "SimpleCUnitTestUtil.h"

bool findInList(const char *s, const char **list, int listSize)
{
	for (int i = 0; i < listSize; i++) {
		if (strcmp(s, list[i]) == 0) {
			return true;
		}
	}
	return false;
}