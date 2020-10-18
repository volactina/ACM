/*
作者：yewenhao
链接：https://leetcode-cn.com/problems/transpose-matrix/solution/867-zhuan-zhi-ju-zhen-ti-jie-cyu-yan-by-yewenhao/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
// #define DEBUG
void print(const int **A, int row, int col)
{
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}
int** transpose(int** A, int ASize, int* AColSize, int* returnSize, int** returnColumnSizes)
{
#ifdef DEBUG
    printf("ASize=%d\nAColsize:", ASize);
    for (int i = 0; i < ASize; i++) {
        printf("%d ", AColSize[i]);
    }
    printf("\n");
    print(A, ASize, AColSize[0]);
#endif
    *returnSize = AColSize[0];
    *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < (*returnSize); i++) {
        (*returnColumnSizes)[i] = ASize;
    }
#ifdef DEBUG
    printf("returnSize=%d\nreturnColumnSizes:", *returnSize);
    for (int i = 0; i < (*returnSize); i++) {
        printf("%d ", (*returnColumnSizes)[i]);
    }
    printf("\n");
#endif
    int **ans = (int **)malloc(sizeof(int *) * (*returnSize));
    for (int i = 0; i < (*returnSize); i++) {
        ans[i] = (int *)malloc(sizeof(int) * (*returnColumnSizes)[i]);
        for (int j = 0 ; j < (*returnColumnSizes)[i]; j++) {
            ans[i][j] = A[j][i];
        }
    }
#ifdef DEBUG
    print(ans, *returnSize, (*returnColumnSizes)[0]);
#endif
    return ans;
}