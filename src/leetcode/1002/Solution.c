#define ALPHANUM 26
#define ANSSTRLEN 2
#define MIN(x,y) ((x) < (y)) ? (x) : (y)
#define DEBUG false

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** commonChars(char ** A, int ASize, int* returnSize){
    int alphaCnt[ALPHANUM], currentAlphaCnt[ALPHANUM];
    memset(alphaCnt, 0, sizeof(int) * ALPHANUM);
    for (int i = 0; i < ASize; i++) {
        memset(currentAlphaCnt, 0, sizeof(int) * ALPHANUM);
        for (int j = 0; j < strlen(A[i]); j++) {
            currentAlphaCnt[A[i][j] - 'a']++;
        }
        for (int j = 0; j < ALPHANUM; j++) {
            if (DEBUG) {
                printf("i=%d,j=%c,now=%d,ans=%d\n", i, j + 'a', currentAlphaCnt[j], alphaCnt[j]);
            }
            if (i) {
                alphaCnt[j] = MIN(alphaCnt[j], currentAlphaCnt[j]);
            } else {
                alphaCnt[j] = currentAlphaCnt[j];
            }
            
        }
    }
    char **ans = NULL;
    *returnSize = 0;
    for (int i = 0; i< ALPHANUM; i++) {
        (*returnSize) += alphaCnt[i];
    }
    if (DEBUG) {
        printf("returnSize = %d\n", *returnSize);
    }
    if ((*returnSize) == 0) {
        return ans;
    }
    ans = (char **)malloc(sizeof(char *) * (*returnSize));
    if (ans == NULL) {
        printf("error\n");
        return ans;
    }
    for (int i = 0; i < (*returnSize); i++) {
        ans[i] = (char *)malloc(sizeof(char) * ANSSTRLEN);
        if (ans[i] == NULL) {
            printf("error\n");
            return ans;
        }
    }
    int t = 0;
    for (int i = 0; i < ALPHANUM; i++) {
        for (int j = 0; j < alphaCnt[i]; j++) {
            ans[t][0] = 'a' + i;
            ans[t][1] = '\0';
            t++;
        }
    }
    return ans;
}