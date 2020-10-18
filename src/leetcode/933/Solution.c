/*
作者：yewenhao
链接：https://leetcode-cn.com/problems/number-of-recent-calls/solution/933-zui-jin-de-qing-qiu-ci-shu-ti-jie-cyu-yan-by-y/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#define INTERVAL 3001

typedef struct {
    int cnt;
    int nowt;
    int records;
    int recordt;
    int record[INTERVAL]; //[records, recordt)
} RecentCounter;

RecentCounter* recentCounterCreate()
{
    RecentCounter *obj = (RecentCounter *)malloc(sizeof(RecentCounter));
    obj->cnt = 0;
    obj->nowt = 0;
    obj->records = 0;
    obj->recordt = 0;
    return obj;
}

int recentCounterPing(RecentCounter *obj, int t)
{
    obj->nowt = t;
    while (obj->cnt > 0 && obj->record[obj->records] <= t - INTERVAL) {
        obj->cnt--;
        obj->records = (obj->records + 1) % INTERVAL;
    }
    obj->record[obj->recordt] = t;
    obj->recordt = (obj->recordt + 1) % INTERVAL;
    obj->cnt++;
    return obj->cnt;
}

void recentCounterFree(RecentCounter *obj)
{
    free(obj);
    obj = NULL;
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 
 * recentCounterFree(obj);
*/