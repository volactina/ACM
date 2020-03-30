#include <bits/stdc++.h>
#define MAXN 110

using namespace std;

struct node{
    int a,b,w;
    char c[2];
    bool operator<(node &b) const{
        return this->w<b.w;
    }
}edge[MAXN];
bool cmp(node x,node y){
    return x.w<y.w;
}
int pre[MAXN],n,m,ans[MAXN];
int find_root(int x){
    return (pre[pre[x]]==pre[x])?pre[x]:pre[x]=find_root(pre[x]);
}
bool same(int x,int y){return find_root(x)==find_root(y);}
void combine(int x,int y){
    pre[find_root(y)]=find_root(x);
}
void solve(char invalid){
    for(int i=1;i<=n;i++) pre[i]=i;
    queue<int> q;
    while(!q.empty()) q.pop();
    int mincost=0,mink=0;
    for(int i=1;i<=m;i++){
        if(edge[i].c[0]==invalid||same(edge[i].a,edge[i].b)){
            q.push(edge[i].w);
            continue;
        }
        mincost+=edge[i].w;
        mink++;
        combine(edge[i].a,edge[i].b);
    }
    for(int i=2;i<=n;i++){
        if(!same(1,i)) return;
    }
    if(ans[mink]==-1) ans[mink]=mincost;else ans[mink]=min(ans[mink],mincost);
    for(int i=mink+1;i<=m;i++){
        mincost+=q.front();
        q.pop();
        if(ans[i]==-1) ans[i]=mincost;else ans[i]=min(ans[i],mincost);
    }
    return;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int casenum=1;casenum<=t;casenum++){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++) scanf("%d %d %d %s",&edge[i].a,&edge[i].b,&edge[i].w,edge[i].c);
        sort(edge+1,edge+1+m);
        memset(ans,-1,sizeof(ans));
        solve('B'),solve('R');
        printf("Case #%d:\n",casenum);
        for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
    }
    return 0;
}
