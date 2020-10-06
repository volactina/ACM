#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;

struct node{
    int l,r,id,block;
}Q[MAXN];

bool cmp(node x,node y){
    if(x.block==y.block){
        if(x.r==y.r) return x.l<y.l;
        return x.r<y.r;
    }
    return x.block<y.block;
}
int cnt[MAXN],nowans,a[MAXN];
void Add(int x){
    cnt[a[x]]++;
    if(cnt[a[x]]==1) nowans++;
    return;
}
void Remove(int x){
    cnt[a[x]]--;
    if(cnt[a[x]]==0) nowans--;
    return;
}

int main()
{
    int n,q;
    while(~scanf("%d%d",&n,&q)){
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int sz=sqrt(q);
        for(int i=0;i<q;i++) scanf("%d%d",&Q[i].l,&Q[i].r),Q[i].id=i,Q[i].block=Q[i].l/sz;
        sort(Q,Q+q,cmp);
        //init
        int nowl=1,nowr=n;
        memset(cnt,0,sizeof(cnt)),nowans=0;
        cnt[a[1]]++,cnt[a[n]]++;
        if(a[1]==a[n]) nowans=1;else nowans=2;
        int ans[MAXN];
        for(int i=0;i<q;i++){
            while(nowr>Q[i].r) Add(--nowr);
            while(nowl<Q[i].l) Add(++nowl);
            while(nowr<Q[i].r) Remove(nowr++);
            while(nowl>Q[i].l) Remove(nowl--);
            ans[Q[i].id]=nowans;
        }
        for(int i=0;i<q;i++) printf("%d\n",ans[i]);
    }
    return 0;
}
