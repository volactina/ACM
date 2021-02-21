#include "Solution.h"

/*
本题中一段子数组的最大绝对差有如下特点：
固定子数组的起点，增大终点，最大绝对差是单调不减的；
固定子数组的重点，增大起点，最大绝对差是单调不增的。
因此可以使用双指针/滑动窗口的方式去解。
维护左指针，右指针，当前连续子数组长度和最大连续子数组长度
当更新右指针时，需要判断新加入的滑动窗口的元素是否会改变当前的最大绝对差，这就需要时刻维护当前滑动窗口的最大绝对查，并且可以在滑动的过程中一直维护这个值；最大绝对差实际上就是滑动窗口中最大值和最小值的差，所以需要时刻维护最大值和最小值；这里使用两个堆来分别维护最大值和最小值，同时采用延迟删除的技术；具体算法流程如下：
（1）初始化最大堆/最小堆，双指针等变量
（2）更新右指针，将当前新元素分别插入最大堆和最小堆中
（3）计算当前最大值与最小值的差，不断更新左指针的值直到当前最大绝对差符合阈值
（4）更新当前答案
（5）重复执行2-4步，直到右指针滑到数组结尾
这里采用了延迟删除的技术，也就是当更新左指针的时候，实际上最大堆和最小堆中的某个值已经被删除了，但是仍然保留在了堆中；延迟删除的具体实现就是在构建堆的结构时，堆中每个元素保存的是值和索引的结构体，在查询最大堆或最小堆的top元素时，首先判断这个元素是否已经被删除了，如果已经被删除了就将它pop出这个堆，然后再去查询；是否已经被删除的标准就是当前元素的索引是否小于当前的左指针
时间复杂度分析：
由于每个元素最多被放入堆和从堆中删除各一次，所以总的时间复杂度是O(nlogn)
*/
#define MAX_HEAP_NUM 100010
#define PARENT(x) (((x) - 1) / 2)
#define LEFT(x) ((x) * 2 + 1)
#define RIGHT(x) ((x) * 2 + 2)
#define MIN(x,y) (((x) < (y) ? (x) : (y)))
#define MAX(x,y) (((x) < (y) ? (y) : (x)))

typedef struct {
    int value;
    int index;
} HeapElement_t;

typedef struct {
    int size;
    bool isMinHeap;
    HeapElement_t e[MAX_HEAP_NUM];
} Heap_t;

void HeapSwap(HeapElement_t *a, HeapElement_t *b)
{
    HeapElement_t c = *b;
    *b = *a;
    *a = c;
}

void HeapCreate(Heap_t *heap, bool isMinHeap)
{
    heap->size = 0;
    heap->isMinHeap = isMinHeap;
}

HeapElement_t HeapTop(Heap_t *heap)
{
    assert(heap->size > 0);
    return heap->e[0];
}

void HeapPop(Heap_t *heap)
{
    assert(heap->size > 0);
    HeapSwap(&(heap->e[0]), &(heap->e[heap->size - 1]));
    heap->size--;
    int nowId = 0;
    int nowValue = heap->e[nowId].value;
    while (LEFT(nowId) < heap->size) {
        int cmpValue = heap->e[LEFT(nowId)].value;
        int cmpId = LEFT(nowId);
        if ((RIGHT(nowId) < heap->size) &&
            ((heap->isMinHeap && heap->e[LEFT(nowId)].value > heap->e[RIGHT(nowId)].value) ||
            (!heap->isMinHeap && heap->e[LEFT(nowId)].value < heap->e[RIGHT(nowId)].value))) {
            cmpValue = heap->e[RIGHT(nowId)].value;
            cmpId = RIGHT(nowId);
        }
        bool NeedSwap = (heap->isMinHeap) ? (nowValue > cmpValue) : (nowValue < cmpValue);
        if (!NeedSwap) {
            break;
        }
        HeapSwap(&(heap->e[nowId]), &(heap->e[cmpId]));
        nowId = cmpId;
        nowValue = heap->e[nowId].value;
    }
}

void HeapAdd(Heap_t *heap, int value, int index)
{
    heap->e[heap->size].value = value;
    heap->e[heap->size].index = index;
    (heap->size)++;
    int nowId = heap->size - 1;
    int nowValue = heap->e[nowId].value;
    while (PARENT(nowId) >= 0) {
        int cmpValue = heap->e[PARENT(nowId)].value;
        int cmpId = PARENT(nowId);
        bool NeedSwap = (heap->isMinHeap) ? (nowValue < cmpValue) : (nowValue > cmpValue);
        if (!NeedSwap) {
            break;
        }
        HeapSwap(&(heap->e[nowId]), &(heap->e[cmpId]));
        nowId = cmpId;
        nowValue = heap->e[nowId].value;
    }
}

int GetMinorMaxValue(Heap_t *heap, int left)
{
    assert(heap->size > 0);
    HeapElement_t topElement = HeapTop(heap);
    while (topElement.index < left) {
        // printf("pop index=%d,left=%d\n", topElement.index, left);
        HeapPop(heap);
        topElement = HeapTop(heap);
    }
    return topElement.value;
}

int MaxAbsoluteDiff(Heap_t *minHeap, Heap_t *maxHeap, int left)
{
    // printf("minheap=%d\n", minHeap->size);
    int minValue = GetMinorMaxValue(minHeap, left);
    // printf("maxheap=%d\n", maxHeap->size);
    int maxValue = GetMinorMaxValue(maxHeap, left);
    // printf("max=%d,min=%d,max-min=%d\n", maxValue, minValue, maxValue - minValue);
    return maxValue - minValue;
}

int longestSubarray(int* nums, int numsSize, int limit)
{
    Heap_t minHeap, maxHeap;
    HeapCreate(&minHeap, true);
    HeapCreate(&maxHeap, false);
    int left = 0;
    int right = 0;
    int lmax = 1;
    HeapAdd(&minHeap, nums[0], 0);
    HeapAdd(&maxHeap, nums[0], 0);
    while (right + 1 < numsSize) {
        right++;
        // printf("right=%d\n", right);
        HeapAdd(&minHeap, nums[right], right);
        HeapAdd(&maxHeap, nums[right], right);
        while (MaxAbsoluteDiff(&minHeap, &maxHeap, left) > limit) {
            /* We don't need to worry if left > right because diff would be 0 when left == right */
            // printf("left:%d->%d\n", left, left + 1);
            left++;
        }
        lmax = MAX(lmax, right - left + 1);
    }
    return lmax;
}

// 作者：yewenhao
// 链接：https://leetcode-cn.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/solution/1438cyu-yan-by-yewenhao-oo2s/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。