#include <bits/stdc++.h>
#define ASSERT(X) if(!(X)) while(1);
#define MAXN 110
//#define DEBUG

using namespace std;

int main()
{
    int n,m,x,y,nowx,nowy,maxnum[MAXN],visitnum;
    bool visited[MAXN][MAXN];
    memset(visited,false,sizeof(visited));
    #ifndef DEBUG
    cin>>n>>m>>x>>y;
    #else
    srand((unsigned)time(NULL));
    int nmin=1,nmax=10,mmin=1,mmax=10;
    n=rand()%(nmax-nmin+1)+nmin;
    m=rand()%(mmax-mmin+1)+mmin;
    x=rand()%n+1;
    y=rand()%m+1;
    //y=1;
    cout<<n<<" "<<m<<" "<<x<<" "<<y<<endl;
    #endif // DEBUG

    nowx=x,nowy=y,visitnum=1,visited[nowx][nowy]=true;
    for(int i=1;i<=n;i++) maxnum[i]=m;
    if(n==1){
        nowx=1,nowy=1;
        if(nowy!=y&&!visited[nowx][nowy]) cout<<nowx<<" "<<nowy<<endl,visitnum++;
        ASSERT(nowx>=1&&nowx<=n&&nowy>=1&&nowy<=m);
        visited[nowx][nowy]=true;
        while(nowy+1<=m){
            nowy++;
            if(nowy!=y&&!visited[nowx][nowy]) cout<<nowx<<" "<<nowy<<endl,visitnum++;
            ASSERT(nowx>=1&&nowx<=n&&nowy>=1&&nowy<=m);
            visited[nowx][nowy]=true;
        }
        //ASSERT(visitnum==n*m);
        return 0;
    }
    if(y==1){
        nowx=1;
        if(nowx!=x&&!visited[nowx][nowy]) cout<<nowx<<" "<<nowy<<endl,visitnum++;
        ASSERT(nowx>=1&&nowx<=n&&nowy>=1&&nowy<=m);
        visited[nowx][nowy]=true;
        while(nowx+1<=n){
            nowx++;
            if(nowx!=x&&!visited[nowx][nowy]) cout<<nowx<<" "<<nowy<<endl,visitnum++;
            ASSERT(nowx>=1&&nowx<=n&&nowy>=1&&nowy<=m);
            visited[nowx][nowy]=true;
        }
        if (m==1) return 0;
        nowx=n,nowy=2;
        if(!visited[nowx][nowy])cout<<nowx<<" "<<nowy<<endl,visitnum++;
        ASSERT(nowx>=1&&nowx<=n&&nowy>=1&&nowy<=m);
        visited[nowx][nowy]=true;
        do{
            nowx=1;
            if(!visited[nowx][nowy]) cout<<nowx<<" "<<nowy<<endl,visitnum++;
            ASSERT(nowx>=1&&nowx<=n&&nowy>=1&&nowy<=m);
            visited[nowx][nowy]=true;
            while(nowx+1<n){
                nowx++;
                if(!visited[nowx][nowy]) cout<<nowx<<" "<<nowy<<endl,visitnum++;
                ASSERT(nowx>=1&&nowx<=n&&nowy>=1&&nowy<=m);
                visited[nowx][nowy]=true;
            }
            nowx++,nowy++;
            if(nowx>n||nowy>m) return 0;
            if(!visited[nowx][nowy]) cout<<nowx<<" "<<nowy<<endl,visitnum++;
            ASSERT(nowx>=1&&nowx<=n&&nowy>=1&&nowy<=m);
            visited[nowx][nowy]=true;
        }while(1);
        //ASSERT(visitnum==n*m);
        return 0;
    }
    maxnum[x]=y-1;
    while(nowy+1<=m){
        nowy++;
        if(!visited[nowx][nowy]) cout<<nowx<<" "<<nowy<<endl,visitnum++;
        ASSERT(nowx>=1&&nowx<=n&&nowy>=1&&nowy<=m);
        visited[nowx][nowy]=true;
    }
    while(nowx+1<=n){
        nowx++;
        if(!visited[nowx][nowy]) cout<<nowx<<" "<<nowy<<endl,visitnum++;
        ASSERT(nowx>=1&&nowx<=n&&nowy>=1&&nowy<=m);
        visited[nowx][nowy]=true;
        maxnum[nowx]=m-1;
    }
    while(nowy-1>=1){
        nowy--;
        if(!visited[nowx][nowy])cout<<nowx<<" "<<nowy<<endl,visitnum++;
        ASSERT(nowx>=1&&nowx<=n&&nowy>=1&&nowy<=m);
        visited[nowx][nowy]=true;
    }
    if(nowx-1<1){
        //ASSERT(visitnum==n*m);
        return 0;
    }
    nowx--;
    if(!visited[nowx][nowy])cout<<nowx<<" "<<nowy<<endl,visitnum++;
    ASSERT(nowx>=1&&nowx<=n&&nowy>=1&&nowy<=m);
    visited[nowx][nowy]=true;
    int minrow=1;
    if(x==1&&y==1) minrow=2;
    do{
        nowy=maxnum[nowx];
        if(!visited[nowx][nowy])cout<<nowx<<" "<<nowy<<endl,visitnum++;
        ASSERT(nowx>=1&&nowx<=n&&nowy>=1&&nowy<=m);
        visited[nowx][nowy]=true;
        while(nowy-1>=2){
            nowy--;
            if(!visited[nowx][nowy])cout<<nowx<<" "<<nowy<<endl,visitnum++;
            ASSERT(nowx>=1&&nowx<=n&&nowy>=1&&nowy<=m);
            visited[nowx][nowy]=true;
        }
        nowx--,nowy=1;
        if(nowx<minrow||nowy<1) break;
        if(!visited[nowx][nowy])cout<<nowx<<" "<<nowy<<endl,visitnum++;
        ASSERT(nowx>=1&&nowx<=n&&nowy>=1&&nowy<=m);
        visited[nowx][nowy]=true;
    }while(true);
    #ifdef DEBUG
    cout<<n<<" "<<m<<" "<<x<<" "<<y<<endl;
    #endif // DEBUG
    ASSERT(visitnum==n*m);
    return 0;
}
