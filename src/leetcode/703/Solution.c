#include "Solution.h"
/*
题目中会调用add方法10^4次，考虑到k的范围时10^4，因此每次add操作时间复杂度必须控制在O(k)，这里需要考虑到的一个问题是如果每次都将新add的数据存进来（不说空间上需要另外分配内存），那么到最后即使单次操作时间复杂度控制在了O(n)，那么也会变成10^8（因为add进去了10^4个数）；这里考虑到目标是输出第k大的数，因此实际上只需要存前k大的数即可，这样可以使得每次单词操作的时间复杂度都控制在O(k)
另外的收获点：
qsort用法
快速排序特性：当要排序的数组基本有序时，时间复杂度会退化到O(n^2)
realloc用法（最后并不需要使用）

作者：yewenhao
链接：https://leetcode-cn.com/problems/kth-largest-element-in-a-stream/solution/703cyu-yan-by-yewenhao-9q1x/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

typedef struct {
    int k;
    int *nums;
} KthLargest;

int cmp(const void *a, const void *b)
{
    return *(int*)b - *(int*)a;
}

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest *obj = malloc(sizeof(KthLargest));
    obj->k = k;
    obj->nums = (int*)malloc(sizeof(int) * k);
    for (int i = 0; i < k; i++) {
        obj->nums[i] = INT_MIN;
    }
    if (numsSize == 0) {
        return obj;
    }
    qsort(nums, numsSize, sizeof(int), &cmp);
    memcpy(obj->nums, nums, sizeof(int) * ((numsSize < k) ? numsSize : k));
    // for (int i = 0; i < k; i++) {
    //     printf("%d ", obj->nums[i]);
    // }
    // printf("\n");
    return obj;
}

int kthLargestAdd(KthLargest* obj, int val) {
    /* 永远只存前k大个元素,比当前第k大元素要小的val就不要了 */
    if (val <= obj->nums[obj->k - 1]) {
        return obj->nums[obj->k - 1];
    }
    /* 插入排序,时间复杂度O(k)*/
    for (int i = obj->k - 1; i >= 0; i--) {
        if (i == 0 || obj->nums[i - 1] >= val) {
            obj->nums[i] = val;
            break;
        }
        obj->nums[i] = obj->nums[i - 1];
    }
    /* 不要用qsort,在数组基本有序时快速排序的时间复杂度退化到O(n^2)*/
    // for (int i = 0; i < obj->k; i++) {
    //     printf("%d ", obj->nums[i]);
    // }
    // printf("\n");
    return obj->nums[obj->k - 1];
}

void kthLargestFree(KthLargest* obj) {
    free(obj->nums);
    obj->nums = NULL;
    free(obj);
    obj = NULL;
}

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);
 
 * kthLargestFree(obj);
*/