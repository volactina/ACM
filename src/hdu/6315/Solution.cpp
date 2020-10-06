#include <bits/stdc++.h>
#define MAXN 100010
#define ll long long
#define debug false
#define debughuge false

using namespace std;

struct node{
    int l,r;
    ll sum,store,lazy,left,add;
}tree[MAXN<<2];
ll b[MAXN];
void push_up(int id);
void push_down(int id);
void build_tree(int id,int l,int r);
void update(int id,int l,int r,ll num);
ll query(int id,int l,int r);

void push_up(int id){
    tree[id].sum=tree[id<<1].sum+tree[id<<1|1].sum;
    tree[id].store=min(tree[id<<1].store,tree[id<<1|1].store);
    if(tree[id<<1].left==tree[id<<1|1].left){
        tree[id].left=tree[id<<1].left,tree[id].add=tree[id<<1].add+tree[id<<1|1].add;
    }else if(tree[id<<1].left<tree[id<<1|1].left){
        tree[id].left=tree[id<<1].left,tree[id].add=tree[id<<1].add;
    }else{
        tree[id].left=tree[id<<1|1].left,tree[id].add=tree[id<<1|1].add;
    }
    return;
}
void push_down(int id){
    if(tree[id].lazy){
        update(id<<1,tree[id<<1].l,tree[id<<1].r,tree[id].lazy);
        update(id<<1|1,tree[id<<1|1].l,tree[id<<1|1].r,tree[id].lazy);
        tree[id].lazy=0;
    }
    return;
}
void build_tree(int id,int l,int r){
    tree[id].l=l,tree[id].r=r,tree[id].lazy=tree[id].store=tree[id].sum=0;
    if(l==r){
        tree[id].left=b[l],tree[id].add=1;
        return;
    }
    int mid=(l+r)>>1;
    build_tree(id<<1,l,mid),build_tree(id<<1|1,mid+1,r);
    push_up(id);
    return;
}
void update(int id,int l,int r,ll num){
    if(tree[id].l==l&&tree[id].r==r){
        if(l==r){
            tree[id].store+=num;
            while(tree[id].store>=tree[id].left){
                tree[id].store-=tree[id].left;
                tree[id].sum++;
                tree[id].left=b[l];
                tree[id].add=1;
            }
            tree[id].left-=tree[id].store;
            tree[id].store=0;
        }else{
            tree[id].lazy+=num;
            tree[id].store+=num;
            while(tree[id].store>=tree[id].left){
                tree[id].store-=tree[id].left;
                tree[id].sum+=tree[id].add;
                tree[id].left=0;
                push_down(id);
                push_up(id);
            }
            tree[id].left-=tree[id].store;
            tree[id].store=0;
        }
        return;
    }
    push_down(id);
    int leftr=tree[id<<1].r,rightl=tree[id<<1|1].l;
    if(r<=leftr){
        update(id<<1,l,r,num);
    }else if(l>=rightl){
        update(id<<1|1,l,r,num);
    }else{
        update(id<<1,l,leftr,num),update(id<<1|1,rightl,r,num);
    }
    push_up(id);
    return;
}
ll query(int id,int l,int r){
    if(tree[id].l==l&&tree[id].r==r){
        return tree[id].sum;
    }
    push_down(id);
    ll ans;
    int leftr=tree[id<<1].r,rightl=tree[id<<1|1].l;
    if(r<=leftr){
        ans=query(id<<1,l,r);
    }else if(l>=rightl){
        ans=query(id<<1|1,l,r);
    }else{
        ans=query(id<<1,l,leftr)+query(id<<1|1,rightl,r);
    }
    push_up(id);
    return ans;
}

int main()
{
    if(debug){
        int n,q;
        while(~scanf("%d%d",&n,&q)){
            if(debughuge) for (int i=1;i<=n;i++) b[i]=i;
            else{
                for (int i=1;i<=n;i++) scanf("%I64d",&b[i]);
            }
            int a[MAXN];
            memset(a,0,sizeof(a));
            char op[20];
            int l,r;
            while(q--){
                scanf("%s%d%d",op,&l,&r);
                if(op[0]=='a'){
                    for (int i=l;i<=r;i++) a[i]++;
                }else if(op[0]=='q'){
                    ll ans=0;
                    for (int i=l;i<=r;i++) ans+=a[i]/b[i];
                    printf("%I64d\n",ans);
                }
            }
        }
        return 0;
    }
    int n,q;
    while(~scanf("%d%d",&n,&q)){
        if(debughuge) for (int i=1;i<=n;i++) b[i]=i;
        else{
            for (int i=1;i<=n;i++) scanf("%I64d",&b[i]);
        }
        build_tree(1,1,n);
        char op[20];
        int l,r;
        while(q--){
            scanf("%s%d%d",op,&l,&r);
            if(op[0]=='a'){
                update(1,l,r,1);
            }else if(op[0]=='q'){
                printf("%I64d\n",query(1,l,r));
            }
        }
    }
    return 0;
}
