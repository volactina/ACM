#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1010
#define MAXV 1010

using namespace std;

int main()
{
    int t,N,V,dp[MAXV],w[MAXN],v[MAXN];
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&N,&V);
        memset(dp,0,sizeof(dp));
        for (int i=0;i<N;i++) scanf("%d",&w[i]);
        for (int i=0;i<N;i++) scanf("%d",&v[i]);
        for (int i=0;i<N;i++){
            for (int j=V;j>=0;j--){
                if (j<v[i]) continue;
                dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
            }
        }
        printf("%d\n",dp[V]);
    }
    return 0;
}
