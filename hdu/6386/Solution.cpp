#include <bits/stdc++.h>
#define inf 1000000000
#define MAXN 100010
#define MAXM 200010

using namespace std;

int pre[MAXN],d[MAXN];
set<int> from[MAXN];
bool inq[MAXN];
queue<int> q;

struct EDGE{
	int next;   //下一条边的存储下标
	int to;     //这条边的终点
	int w;      //权值
}edge[MAXM*2];
int n,m,cnt,head[MAXN];  //head[i]表示以i为起点的第一条边
void Add(int u, int v, int w) {  //起点u, 终点v, 权值w
	edge[++cnt].next = head[u];
	edge[cnt].w = w;
	edge[cnt].to = v;
	head[u] = cnt;    //第一条边为当前边
}

void init(){
    memset(head,-1,sizeof(head));
    memset(edge,0,sizeof(edge));
    for(int i=1;i<=n;i++){
        d[i]=inf;
        pre[i]=i;
        from[i].clear();
    }
    d[0]=0;
    cnt=0;
    while(!q.empty()) q.pop();
    memset(inq,false,sizeof(inq));
    return;
}
//int find_root(int x){
//    return (pre[pre[x]]==pre[x])?pre[x]:(pre[x]=find_root(pre[x]));
//}
int find_root(int x){
    return (x==pre[x])?pre[x]:(pre[x]=find_root(pre[x]));
}
bool same_root(int x,int y){
    return find_root(x)==find_root(y);
}
void merge_root(int x,int y){
    pre[find_root(x)]=find_root(y);
    return;
}

int main()
{
    while(~scanf("%d%d",&n,&m)){
        init();
        for(int i=0;i<m;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            Add(x,y,z);
            Add(y,x,z);
            merge_root(x,y);
        }
        if(!same_root(1,n)){
            printf("-1\n");
            continue;
        }
        for(int i=head[1];i!=0;i=edge[i].next){
            int to=edge[i].to;
            d[to]=1;
            from[to].insert(edge[i].w);
            q.push(to);
            inq[to]=true;
        }
        while(!q.empty()){
            int now=q.front();
            q.pop();
            inq[now]=false;
            for(int i=head[now];i!=0;i=edge[i].next){
                int to=edge[i].to;
                bool join=false,havesame=false;
                for(set<int>::iterator it=from[now].begin();it!=from[now].end();it++){
                    if((*it)==edge[i].w){
                        havesame=true;
                        break;
                    }
                }
                if(havesame){
                    if(d[now]<d[to]){
                        d[to]=d[now];
                        from[to].clear();
                        from[to].insert(edge[i].w);
                        join=true;
                    }else if(d[now]==d[to]){
                        if(from[to].find(edge[i].w)==from[to].end()){
                            from[to].insert(edge[i].w);
                            join=true;
                        }
                    }
                }else{
                    if(d[now]+1<d[to]){
                        d[to]=d[now]+1;
                        from[to].clear();
                        from[to].insert(edge[i].w);
                        join=true;
                    }else if(d[now]+1==d[to]){
                        if(from[to].find(edge[i].w)==from[to].end()){
                            from[to].insert(edge[i].w);
                            join=true;
                        }
                    }
                }
                if(join&&!inq[to]){
                    inq[to]=true;
                    q.push(to);
                }
            }
        }
        printf("%d\n",d[n]);
    }
    return 0;
}
