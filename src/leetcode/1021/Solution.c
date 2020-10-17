/*
作者：yewenhao
链接：https://leetcode-cn.com/problems/remove-outermost-parentheses/solution/1021-shan-chu-zui-wai-ceng-de-gua-hao-ti-jie-cyu-y/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

char * removeOuterParentheses(char *S)
{
    char *ans = (char *)malloc(strlen(S) + 1);
    ans[0] = 0;
    int s = 0;
    int t = 0;
    int stackcnt = 0;
    for (int i = 0; i < strlen(S); i++) {
        if (S[i] == '(') {
            stackcnt++;
        } else {
            stackcnt--;
        }
        t = i;
        if (stackcnt) {
            continue;
        }
        
        if (t - s > 1) {
            strncat(ans, S + s + 1, t - s - 1);
        }
        s = i + 1;
    }
    return ans;
} 