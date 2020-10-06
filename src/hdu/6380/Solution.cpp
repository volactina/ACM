#include <bits/stdc++.h>
#define MAXN 200010

using namespace std;

int n,m,k,degree[MAXN],maxdegree,cnt;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&k);
        memset(degree,0,sizeof(degree));
        maxdegree=0;
        cnt=n;
        for(int i=0;i<m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            degree[a]++;
            degree[b]++;
            if(degree[a]>maxdegree){
                maxdegree=degree[a];
            }
            if(degree[b]>maxdegree){
                maxdegree=degree[b];
            }
            cnt--;
        }
        int ans=maxdegree+cnt-1;
        int edge_left=m-maxdegree;
        if(edge_left>0) ans+=min(k,edge_left);
        cout<<ans<<endl;
    }
    return 0;
}
