#include "Solution.h"

/* 暴力模拟，会超出时间限制 */
char * BrutalFore(char * S)
{
    int startIndex = 0;
    bool hasRepeat = true;
    char repeatCh;
    int ansLen = strlen(S);
    while (hasRepeat) {
        hasRepeat = false;
        repeatCh = S[startIndex];
        for (int i = startIndex + 1; i < strlen(S); i++) {
            if (S[i] == '#') {
                continue;
            }
            if (repeatCh == S[i]) {
                S[startIndex] = S[i] = '#';
                ansLen -= 2;
                hasRepeat = true;
                startIndex = i + 1;
                for (int j = startIndex - 1; j >= 0; j--) {
                    if (S[j] != '#') {
                        startIndex = j;
                    }
                }
                // startIndex = (startIndex - 1 <= 0) ? 0 : startIndex - 1;
                break;
            } else {
                while (S[++startIndex] == '#'){}
                repeatCh = S[startIndex];
            }
        }
        // printf("%s\n", S);
    }
    char *ans = (char*) malloc(ansLen + 1);
    for (int i = 0, t = 0; i <= strlen(S); i++) {
        if (S[i] == '#') {
            continue;
        }
        ans[t++] = S[i];
    }
    return ans;
}

/* 优化项1：每次都不保存#字符，这样字符串会越来越短 */
char * BrutalForeOp1(char * S)
{
    int ansLen = strlen(S);
    char * ans = malloc(ansLen + 1);
    bool hasRepeat = true;
    while (hasRepeat) {
        for (int i = 0, t = 0; i <= strlen(S); i++) {
            if (S[i] == '#') {
                continue;
            }
            ans[t++] = S[i];
        }
        strcpy(S, ans);
        hasRepeat = false;
        for (int i = 1; i < strlen(S); i++) {
            if (S[i] == S[i - 1]) {
                S[i] = S[i - 1] = '#';
                hasRepeat = true;
            }
        }
    }
    for (int i = 0, t = 0; i <= strlen(S); i++) {
        if (S[i] == '#') {
            continue;
        }
        ans[t++] = S[i];
    }
    return ans;
}

char * removeDuplicates(char * S)
{
    return BrutalForeOp1(S);
}

// 作者：yewenhao
// 链接：https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string/solution/1047cyu-yan-by-yewenhao-29gn/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。