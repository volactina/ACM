/*
作者：yewenhao
链接：https://leetcode-cn.com/problems/baseball-game/solution/682-bang-qiu-bi-sai-ti-jie-cyu-yan-by-yewenhao/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

// #define DEBUG

int calPoints(char ** ops, int opsSize)
{
    int stack[opsSize];
    int stacktop = -1;
    int sum = 0;
    for (int i = 0; i < opsSize; i++) {
#ifdef DEBUG
        printf("i=%d\n", i);
#endif
        if (ops[i][0] == 'C') {
            sum -= stack[stacktop--];
            continue;
        }
        int newscore;
        switch(ops[i][0]) {
            case '+':
                newscore = stack[stacktop] + stack[stacktop - 1];
                break;
            case 'D':
                newscore = stack[stacktop] * 2;
                break;
            default:
                newscore = atoi(ops[i]);
                break;
        }
        stack[++stacktop] = newscore;
        sum += newscore;
#ifdef DEBUG
        printf("sum=%d\n", sum);
#endif
    }
    return sum;
}