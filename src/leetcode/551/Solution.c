#include "Solution.h"

bool checkRecord(char * s){
    int cntA = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == 'A') {
            cntA++;
        }
        if (cntA > 1 || (i > 1 && s[i] == 'L' && s[i - 1] == 'L' && s[i - 2] == 'L')) {
            return false;
        }
    }
    return true;
}

// 作者：yewenhao
// 链接：https://leetcode-cn.com/problems/student-attendance-record-i/solution/551cyu-yan-by-yewenhao-vfsj/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。