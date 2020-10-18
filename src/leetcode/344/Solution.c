/*
作者：yewenhao
链接：https://leetcode-cn.com/problems/reverse-string/solution/344-fan-zhuan-zi-fu-chuan-ti-jie-cyu-yan-by-yewenh/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
void reverseString(char* s, int sSize)
{
    for (int i = 0; i < sSize / 2; i++) {
        int ri = sSize - i - 1;
        char tmp = s[ri];
        s[ri] = s[i];
        s[i] = tmp; 
    }
}