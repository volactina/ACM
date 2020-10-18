/*
作者：yewenhao
链接：https://leetcode-cn.com/problems/implement-strstr/solution/28-shi-xian-strstrti-jie-cyu-yan-by-yewenhao/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
int strStr(char * haystack, char * needle)
{
    char *loc = strstr(haystack, needle);
    return loc ? loc - haystack : -1;
}