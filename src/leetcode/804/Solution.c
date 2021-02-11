#include "Solution.h"

/*
考虑这样一种hash方式，将.对应为0，-对应为1，则每一种单词翻译可以唯一的映射到一个数字上，于是只要统计不同数字的个数即可
每个单词最长12位，每个摩尔斯编码最长4位，因此最长48位二进制可以搞定
*/
#define MAX_ALPHA_NUM 26
#define MAX_MORS_LEN 10
#define MAX_WORD_LEN 100
int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

/* count unique number in nums, O(nlogn) */
int UniqueNum(int *nums, int numsSize)
{
    if (numsSize == 0) {
        return 0;
    }
    qsort(nums, numsSize, sizeof(int), &cmp);
    int cnt = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1]) {
            cnt++;
        }
    }
    return cnt;
}

int Word2Num(char *word)
{
    const char MorseCode[MAX_ALPHA_NUM][MAX_MORS_LEN] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    long num = 0;
    for (int i = 0; i < strlen(word); i++) {
        int morseIndex = word[i] - 'a';
        for (int j = 0; j < strlen(MorseCode[morseIndex]); j++) {
            num |= (MorseCode[morseIndex][j] == '.') ? 0 : 1;
            num <<= 1;
        }
    }
    return num;                                                       
}
int uniqueMorseRepresentations(char ** words, int wordsSize)
{
    long wordsNum[MAX_WORD_LEN];
    int ans = 0;
    for (int i = 0; i < wordsSize; i++) {
        long num = Word2Num(words[i]);
        bool exist = false;
        for (int j = 0; j < ans; j++) {
            if (wordsNum[j] == num) {
                exist = true;
                break;
            }
        }
        if (!exist) {
            wordsNum[ans++] = num;
        }
    }
    return ans;
}

// 作者：yewenhao
// 链接：https://leetcode-cn.com/problems/unique-morse-code-words/solution/804cyu-yan-by-yewenhao-8nr5/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。