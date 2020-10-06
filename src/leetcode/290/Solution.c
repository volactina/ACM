#include "Solution.h"

#define MAX_WORDS_NUM 1000
bool wordPattern(char * pattern, char * s){
    int patternNum = strlen(pattern);
    char *words[MAX_WORDS_NUM];
    char *context;
    int wordsNum = 0;
    words[wordsNum] = strtok_r(s, " ", &context);
    while (words[wordsNum] != NULL) {
        wordsNum++;
        words[wordsNum] = strtok_r(NULL, " ", &context);
    }
    if (patternNum != wordsNum) {
        return false;
    }
    for (int i = 0; i < wordsNum; i++) {
        for (int j = i + 1; j < wordsNum; j++) {
            if ((strcmp(words[i], words[j]) == 0 && pattern[i] != pattern[j]) ||
                (strcmp(words[i], words[j]) != 0 && pattern[i] == pattern[j])) {
                return false;
            }
        }
    }
    return true;
}