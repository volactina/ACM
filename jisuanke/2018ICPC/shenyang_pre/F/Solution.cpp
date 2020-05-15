#include <bits/stdc++.h>

using namespace std;

const int inf=1000000000;
const int maxn=20000,maxm=500000;
struct dinic{
    struct Edge{
        int v,f,nxt;
    };
    int n,src,sink;
    int g[maxn+10];
    int nume;
    Edge e[maxm*2+10];
    void addege(int u,int v,int c){
        e[++nume].v=v;
        e[nume].f=c;
        e[nume].nxt=g[u];
        g[u]=nume;
        e[++nume].v=u;
        e[nume].f=0;
        e[nume].nxt=g[v];
        g[v]=nume;
    }
    void init(){
        memset(g,0,sizeof(g));
        nume=1;
    }
    queue<int> que;
    bool vis[maxn+10];
    int dist[maxn+10];
    void bfs(){
        memset(dist,0,sizeof(dist));
        while(!que.empty()) que.pop();
        vis[src]=true;
        que.push(src);
        while(!que.empty()){
            int u=que.front();
            que.pop();
            for(int i=g[u];i;i=e[i].nxt)
            if(e[i].f&&!vis[e[i].v]){
                que.push(e[i].v);
                dist[e[i].v]=dist[u]+1;
                vis[e[i].v]=true;
            }
        }
    }
    int dfs(int u,int delta){
        if(u==sink){
            return delta;
        }else{
            int ret=0;
            for(int i=g[u];delta&&i;i=e[i].nxt)
            if(e[i].f&&dist[e[i].v]==dist[u]+1){
                int dd=dfs(e[i].v,min(e[i].f,delta));
                e[i].f-=dd;
                e[i^1].f+=dd;
                delta-=dd;
                ret+=dd;
            }
            return ret;
        }
    }
    int maxflow(){
        int ret=0;
        while(true){
            memset(vis,0,sizeof(vis));
            bfs();
            if(!vis[sink]) return ret;
            ret+=dfs(src,inf);
        }
    }

}DINIC;

bool lowbound_flow(int n,int source,int sink,vector<int> u,vector<int> v,vector<int> L,vector<int> U){
        DINIC.init();
        vector<int> tot_in(n+1),tot_out(n+1);
        for(int i=0;i<(int)u.size();++i){
            if(U[i]<L[i]){
                return 0;
            }
            tot_in[v[i]]+=L[i];
            tot_out[u[i]]+=L[i];
            DINIC.addege(u[i],v[i],U[i]-L[i]);
        }
        DINIC.addege(sink,source,1000000000);
        int super_source=n+1;
        int super_sink=n+2;
        DINIC.src=super_source;
        DINIC.sink=super_sink;
        for(int i=1;i<=n;++i){
            DINIC.addege(super_source,i,tot_in[i]);
            DINIC.addege(i,super_sink,tot_out[i]);
        }
        int ans=DINIC.maxflow();
        //cout<<ans<<endl;
        for(int i=DINIC.g[super_source];i;i=DINIC.e[i].nxt){
            if(DINIC.e[i].f!=0){
                return 0;
            }
        }
        return 1;
}

int main()
{
    int n,m,k,nowcasenum=0;
    map<pair<int,int>,int> edges;
    while(~scanf("%d%d%d",&n,&m,&k)){
        edges.clear();
        nowcasenum++;
        int l,r;
        scanf("%d%d",&l,&r);
        //1..n+1 n+1..n+m source n+m+1 sink n+m+2
        int vnum=n+m+2,source=n+m+1,sink=n+m+2;
        vector<int> u,v,L,U;
        u.clear(),v.clear(),L.clear(),U.clear();
        for(int i=0;i<k;i++){
            pair<int,int> tmp;
            scanf("%d%d",&tmp.first,&tmp.second);
            edges[tmp]++;
        }
        for(map<pair<int,int>,int>::iterator it=edges.begin();it!=edges.end();it++){
            int a=it->first.first,b=it->first.second,c=it->second;
            u.push_back(a);
            v.push_back(b+n);
            L.push_back(0);
            U.push_back(c);
        }
        for(int i=1;i<=n;i++){
            u.push_back(source);
            v.push_back(i);
            L.push_back(l);
            U.push_back(r);
        }
        for(int i=1;i<=m;i++){
            u.push_back(i+n);
            v.push_back(sink);
            L.push_back(l);
            U.push_back(r);
        }
        printf("Case %d: ",nowcasenum);
        if(lowbound_flow(vnum,source,sink,u,v,L,U)) printf("Yes\n");else printf("No\n");
    }
    return 0;
}
