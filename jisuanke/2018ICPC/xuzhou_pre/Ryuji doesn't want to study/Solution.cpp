#include <bits/stdc++.h>
#define MAXN 100010
#define ll long long

using namespace std;

ll a[MAXN],posta[MAXN];
struct SegmentTree{
    ll sum[MAXN<<2],lazynum[MAXN<<2];
    void push_up(int id,int tl,int tr){
        sum[id]=sum[id<<1]+sum[id<<1|1];
        return;
    }
    void push_down(int id,int tl,int tr){
        if(lazynum[id]){
            int mid=(tl+tr)/2;
            add(id<<1,tl,mid,tl,mid,lazynum[id]);
            add(id<<1|1,mid+1,tr,mid+1,tr,lazynum[id]);
            lazynum[id]=0;
        }
        return;
    }
    void build_tree(int id,int tl,int tr){
        if(tl==tr){
            sum[id]=posta[tl];
            lazynum[id]=0;
            return;
        }
        int mid=(tl+tr)/2;
        build_tree(id<<1,tl,mid);
        build_tree(id<<1|1,mid+1,tr);
        push_up(id,tl,tr);
        return;
    }
    void add(int id,int tl,int tr,int ql,int qr,ll num){
        if(tl==ql&&tr==qr){
            sum[id]+=num*(qr-ql+1);
            lazynum[id]+=num;
            return;
        }
        push_down(id,tl,tr);
        int mid=(tl+tr)/2;
        if(qr<=mid) add(id<<1,tl,mid,ql,qr,num);
        else if(ql>mid) add(id<<1|1,mid+1,tr,ql,qr,num);
        else add(id<<1,tl,mid,ql,mid,num),add(id<<1|1,mid+1,tr,mid+1,qr,num);
        push_up(id,tl,tr);
        return;
    }
    ll query(int id,int tl,int tr,int ql,int qr){
        if(tl==ql&&tr==qr){
            return sum[id];
        }
        push_down(id,tl,tr);
        int mid=(tl+tr)/2;
        ll ans=0;
        if(qr<=mid) ans=query(id<<1,tl,mid,ql,qr);
        else if(ql>mid) ans=query(id<<1|1,mid+1,tr,ql,qr);
        else ans=query(id<<1,tl,mid,ql,mid)+query(id<<1|1,mid+1,tr,mid+1,qr);
        push_up(id,tl,tr);
        return ans;
    }
}ST;

int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    posta[n]=a[n];
    for(int i=n-1;i>=1;i--) posta[i]=posta[i+1]+a[i];
    ST.build_tree(1,1,n);
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int l,r;
            scanf("%d%d",&l,&r);
            ll ans;
            if(r==n){
                if(l==r) ans=ST.query(1,1,n,l,l);
                else ans=(r-l+1)*ST.query(1,1,n,l,l)-ST.query(1,1,n,l+1,r);
            }else{
                ans=(r-l+1)*ST.query(1,1,n,l,l)-ST.query(1,1,n,l+1,r+1);
            }
            printf("%lld\n",ans);
        }else{
            int pos;
            ll num;
            scanf("%d%lld",&pos,&num);
            ST.add(1,1,n,1,pos,num-a[pos]);
            a[pos]=num;
        }
    }
    return 0;
}
