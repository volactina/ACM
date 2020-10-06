/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize){
    
    int *ans=(int *)malloc(sizeof(int)*numsSize);
    printf("%d\n",numsSize);
    printf("%d\n",nums[0]);
    ans[0]=nums[0];
    printf("%d\n",ans[0]);
    for(int i=1;i<numsSize;i++){
        ans[i]=ans[i-1]+nums[i];
        printf("%d\n",ans[i]);
    }
    *returnSize=numsSize;
    return ans;
}