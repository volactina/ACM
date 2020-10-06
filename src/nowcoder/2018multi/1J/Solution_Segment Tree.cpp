#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
//线段树维护区间和,即[L,R]区间内有多少数字是第1次出现的
int tot[MAXN<<2];
void push_up(int id){
    tot[id]=tot[id<<1]+tot[id<<1|1];
    return;
}
void update(int id,int tl,int tr,int pos){
    if(tl==tr&&tl==pos){
        tot[id]++;
        return;
    }
    int mid=(tl+tr)>>1;
    if(pos<=mid) update(id<<1,tl,mid,pos);else update(id<<1|1,mid+1,tr,pos);
    push_up(id);
    return;
}
int query(int id,int tl,int tr,int ql,int qr){
    if(tl==ql&&tr==qr) return tot[id];
    int mid=(tl+tr)>>1;
    if(qr<=mid) return query(id<<1,tl,mid,ql,qr);
    if(ql>mid) return query(id<<1|1,mid+1,tr,ql,qr);
    return query(id<<1,tl,mid,ql,mid)+query(id<<1|1,mid+1,tr,mid+1,qr);
}
//查询离线操作
struct node{
    int l,r,id;
}Q[MAXN];
bool cmp(node x,node y){
    return x.r<y.r;
}

int main(){
    int n,q,a[MAXN],last[MAXN],first[MAXN],ans[MAXN],cnt,nowr;
while(~scanf("%d%d",&n,&q)){
//预处理
        memset(tot,0,sizeof(tot));
        memset(last,0,sizeof(last)),memset(first,0,sizeof(first)),cnt=0,nowr=1;
//读入n个数字，下标与题目一致从1开始
//顺便计算数字第1次和最后1次出现的位置以及总的不同数字个数
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            last[a[i]]=i;
            if(first[a[i]]==0) first[a[i]]=i,cnt++;
        }
//读入q个询问，按照r从小到大离线排序，记录询问顺序
        for(int i=0;i<q;i++) scanf("%d%d",&Q[i].l,&Q[i].r),Q[i].id=i;
        sort(Q,Q+q,cmp);
//核心代码
        for(int i=0;i<q;i++){
            while(nowr<Q[i].r){
                if(last[a[nowr]]==nowr) update(1,1,n,first[a[nowr]]);
                nowr++;
            }
            ans[Q[i].id]=cnt;
            if(Q[i].l<Q[i].r-1) ans[Q[i].id]-=query(1,1,n,Q[i].l+1,Q[i].r-1);
        }
//按照询问顺序输出结果
        for(int i=0;i<q;i++) printf("%d\n",ans[i]);
    }
    return 0;
}
