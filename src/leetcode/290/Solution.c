#include "Solution.h"

#define MAX_WORDS_NUM 1000
bool wordPattern(char * pattern, char * s)
{
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

#define MAX_WORD_LENGTH 50
typedef struct {
    int id;
    char name[MAX_WORD_LENGTH];
    UT_hash_handle hh;
} my_struct;

bool wordPattern_uthash(char * pattern, char * s)
{
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
    my_struct *users = NULL;
    for (int i = 0; i < patternNum; i++) {
        my_struct *nowPair;
        int id = pattern[i];
        HASH_FIND_INT(users, &id, nowPair);
        if (nowPair == NULL) {
            nowPair = (my_struct *)malloc(sizeof(my_struct));
            nowPair->id = id;
            strcpy(nowPair->name, words[i]);
            HASH_ADD_INT(users, id, nowPair);
        } else {
            if (strcmp(nowPair->name, words[i]) != 0) {
                return false;
            }
        }
    }
    return true;
}