#include "Solution.h"

#define ALPHA_NUM 26
/* 时间复杂度O(26*strlen(s)) */
int firstUniqChar(char * s)
{
    bool repeat[ALPHA_NUM] = {false};
    for (int i = 0; i < strlen(s); i++) {
        if (repeat[s[i] - 'a']) {
            continue;
        }
        for (int j = i + 1; j < strlen(s); j++) {
            if (s[j] == s[i]) {
                repeat[s[i] - 'a'] = true;
                break;
            }
        }
        if (!repeat[s[i] - 'a']) {
            return i;
        }
    }
    return -1;
}

// 作者：yewenhao
// 链接：https://leetcode-cn.com/problems/first-unique-character-in-a-string/solution/387cyu-yan-by-yewenhao-79h2/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。