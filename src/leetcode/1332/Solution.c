/*
作者：yewenhao
链接：https://leetcode-cn.com/problems/remove-palindromic-subsequences/solution/1332-shan-chu-hui-wen-zi-xu-lie-ti-jie-cyu-yan-by-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
bool isPalindrome(char *s)
{
    for (int i = 0; (i < strlen(s)) && (2 * i + 1 <= strlen(s)); i++) {
        if (s[i] != s[strlen(s) - i - 1]) {
            return false;
        }
    }
    return true;
}

int removePalindromeSub(char *s)
{
    if (strlen(s) == 0) {
        return 0;
    }
    if (isPalindrome(s)) {
        return 1;
    }
    return 2;
}