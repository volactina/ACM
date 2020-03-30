#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 200010

using namespace std;

struct node{
    int left,right,maxnum,minnum;
    bool used,lazy;
}tree[MAXN<<2];
vector<int> open[MAXN],close[MAXN];

void build_tree(int id,int l,int r){
    tree[id].left=l,tree[id].right=r,tree[id].used=tree[id].lazy=false;
    if (tree[id].left==tree[id].right){
        return;
    }
    int mid=(l+r)/2;
    build_tree(id<<1,l,mid),build_tree(id<<1|1,mid+1,r);
    return;
}

void update(int id,int l,int r,int t){
    if (tree[id].left==l&&tree[id].right==r){
        if (tree[id].used){
            tree[id].maxnum=max(tree[id].maxnum,t),tree[id].minnum=min(tree[id].minnum,t);
        }else{
            tree[id].used=true,tree[id].maxnum=tree[id].minnum=t;
        }
        tree[id].lazy=true;
        return;
    }
    if (tree[id].lazy){
        update(id<<1,tree[id<<1].left,tree[id<<1].right,tree[id].maxnum);
        update(id<<1,tree[id<<1].left,tree[id<<1].right,tree[id].minnum);
        update(id<<1|1,tree[id<<1|1].left,tree[id<<1|1].right,tree[id].maxnum);
        update(id<<1|1,tree[id<<1|1].left,tree[id<<1|1].right,tree[id].minnum);
        tree[id].lazy=false;
    }
    int leftr=tree[id<<1].right,rightl=tree[id<<1|1].left;
    if (r<=leftr){
        update(id<<1,l,r,t);
    }else if (l>=rightl){
        update(id<<1|1,l,r,t);
    }else{
        update(id<<1,l,leftr,t),update(id<<1|1,rightl,r,t);
    }
    return;
}

void query(int id,int l,int r,int &minnum,int &maxnum,bool &used){
    if (tree[id].left==l&&tree[id].right==r){
        maxnum=tree[id].maxnum,minnum=tree[id].minnum,used=tree[id].used;
        return;
    }
    if (tree[id].lazy){
        update(id<<1,tree[id<<1].left,tree[id<<1].right,tree[id].maxnum);
        update(id<<1,tree[id<<1].left,tree[id<<1].right,tree[id].minnum);
        update(id<<1|1,tree[id<<1|1].left,tree[id<<1|1].right,tree[id].maxnum);
        update(id<<1|1,tree[id<<1|1].left,tree[id<<1|1].right,tree[id].minnum);
        tree[id].lazy=false;
    }
    int leftr=tree[id<<1].right,rightl=tree[id<<1|1].left;
    if (r<=leftr){
        query(id<<1,l,r,minnum,maxnum,used);
    }else if (l>=rightl){
        query(id<<1|1,l,r,minnum,maxnum,used);
    }else{
        query(id<<1,l,leftr,minnum,maxnum,used),query(id<<1|1,rightl,r,minnum,maxnum,used);
    }
    return;
}

int main()
{
    int n,m,w[MAXN];
    while (~scanf("%d%d",&n,&m)){
        build_tree(1,1,n-1);
        for (int i=1;i<=n-1;i++) scanf("%d",&w[i]);
        for (int t=0;t<m;t++){
            int a,b;
            scanf("%d%d",&a,&b);
            if (a>b) swap(a,b);
            update(1,a,b-1,t);
        }
        for (int i=0;i<m;i++){
            open[i].clear(),close[i].clear();
        }
        for (int i=1;i<=n-1;i++){
            int minnum,maxnum;
            bool used;
            query(1,i,i,minnum,maxnum,used);
            if (used) open[minnum].push_back(i),close[maxnum+1].push_back(i);
        }
        int money=0;
        for (int i=0;i<m;i++){
            for (int j=0;j<(int)open[i].size();j++) money+=w[open[i][j]];
            for (int j=0;j<(int)close[i].size();j++) money-=w[close[i][j]];
            printf("%d\n",money);
        }
    }
    return 0;
}
