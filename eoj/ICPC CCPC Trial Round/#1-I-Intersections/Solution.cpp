#include <bits/stdc++.h>
#define MAXN 110

using namespace std;

int main()
{
    int n,degree[MAXN*MAXN];
    bool visited[MAXN*MAXN];
    vector<int> e[MAXN*MAXN];
    scanf("%d",&n);
    memset(degree,0,sizeof(degree));
    memset(visited,false,sizeof(visited));
    for(int i=1;i<=n*n;i++) e[i].clear();
    int etot=2*n*n-2*n,first;
    for(int i=0;i<etot;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        e[a].push_back(b);
        e[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }
    for(int i=1;i<=n*n;i++){
        if(degree[i]==2){
            first=i;
            break;
        }
    }
    int ans[MAXN][MAXN];
    ans[0][0]=first;
    visited[first]=true;
    for(int i=1;i<n;i++){
        int pre=ans[0][i-1];
        for(int j=0;j<(int)e[pre].size();j++){
            if(degree[e[pre][j]]<=3&&!visited[e[pre][j]]){
                ans[0][i]=e[pre][j];
                visited[e[pre][j]]=true;
                break;
            }
        }
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            int pre=ans[i-1][j];
            for(int k=0;k<(int)e[pre].size();k++){
                if(!visited[e[pre][k]]){
                    ans[i][j]=e[pre][k];
                    visited[e[pre][k]]=true;
                    break;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d",ans[i][j]);
            if(j==n-1) printf("\n");else printf(" ");
        }
    }
    return 0;
}