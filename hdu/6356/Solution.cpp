#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010
#define debug false
//#define ASSERT(X) if(!(X)) while(true);
//#define ASSERT(X) if(!(X)){int sz=1;while(sz++){int *num=new int[sz];}}
//#define assert ASSERT
using namespace std;

struct SegmentTree{
    struct node{
        ll sum,minnum;
        bool lazy;
    }tree[4*MAXN];
    void push_down(uint32_t id){
        if(tree[id].lazy){
            tree[2*id].minnum=max(tree[2*id].minnum,tree[id].minnum);
            tree[2*id].lazy=true;
            tree[2*id+1].minnum=max(tree[2*id+1].minnum,tree[id].minnum);
            tree[2*id+1].lazy=true;
            tree[id].lazy=false;
        }
        return;
    }
    void build_tree(){
        memset(tree,0,sizeof(tree));
        return;
    }
    void update(uint32_t id,uint32_t tl,uint32_t tr,uint32_t ul,uint32_t ur,ll num){
        assert(tl<=ul&&ur<=tr);
        if(num<=tree[id].minnum) return;//减枝,不加就是TLE,加了就AC
        if(tl==ul&&tr==ur){
            tree[id].minnum=max(tree[id].minnum,num);
            tree[id].lazy=true;
            return;
        }
        push_down(id);
        uint32_t mid=(tl+tr)/2;
        if(ur<=mid) update(2*id,tl,mid,ul,ur,num);
        else if(ul>mid) update(2*id+1,mid+1,tr,ul,ur,num);
        else update(2*id,tl,mid,ul,mid,num),update(2*id+1,mid+1,tr,mid+1,ur,num);
        return;
    }
    ll query(uint32_t id,uint32_t tl,uint32_t tr,uint32_t ql,uint32_t qr){
        assert(tl==ql&&tr==qr);
        if(ql==qr){
            tree[id].sum=max(tree[id].sum,tree[id].minnum);
            if(debug) return tree[id].sum;
            ll i=(ll)ql;
            return i*tree[id].sum;
        }
        push_down(id);
        uint32_t mid=(tl+tr)/2;
        if(debug) return tree[id].sum=query(2*id,tl,mid,ql,mid)+query(2*id+1,mid+1,tr,mid+1,qr);
        return tree[id].sum=query(2*id,tl,mid,ql,mid)^query(2*id+1,mid+1,tr,mid+1,qr);
    }
}ST;
uint32_t RNG61(uint32_t &x,uint32_t &y,uint32_t &z){
    x=x^(x<<11);
    x=x^(x>>4);
    x=x^(x<<5);
    x=x^(x>>14);
    uint32_t w=x^(y^z);
    x=y;
    y=z;
    z=w;
    return z;
}

int main()
{
    if(debug){
        ST.build_tree();
        int n=10;
        ST.update(1,1,n,1,n,5);
        ST.update(1,1,n,3,6,8);
        ST.update(1,1,n,4,7,6);
        cout<<ST.query(1,1,n,1,n)<<endl;
        return 0;
    }
    int t;
    scanf("%d",&t);
    while(t--){
        int m;
        uint32_t X,Y,Z,n,l,r,v,f1,f2,f3,p=1<<30;
        cin>>n>>m>>X>>Y>>Z;
        ST.build_tree();
        while(m--){
            f1=RNG61(X,Y,Z),f2=RNG61(X,Y,Z),f3=RNG61(X,Y,Z);
            l=min((f1%n)+1,(f2%n)+1);
            r=max((f1%n)+1,(f2%n)+1);
            assert(l>=1&&r<=n&&l<=r);
            v=f3%p;
            ST.update(1,1,n,l,r,(ll)v);
        }
        cout<<ST.query(1,1,n,1,n)<<endl;
    }
    return 0;
}
