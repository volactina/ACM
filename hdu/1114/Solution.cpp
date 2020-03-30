#include <bits/stdc++.h>
#define MAXV 10010

using namespace std;

int main(){
    int t,dp[MAXV],empty_v,full_v,N,V,w,v;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&empty_v,&full_v,&N);
        V=full_v-empty_v,memset(dp,-1,sizeof(dp)),dp[0]=0;
        for (int i=1;i<=N;i++){
            scanf("%d%d",&w,&v);
            for (int j=0;j<=V;j++){
                if(j<v||dp[j-v]<0) continue;
                if(dp[j]>=0) dp[j]=min(dp[j],dp[j-v]+w);else dp[j]=dp[j-v]+w;
            }
        }
        if(dp[V]==-1) printf("This is impossible.\n");
        else printf("The minimum amount of money in the piggy-bank is %d.\n",dp[V]);
    }
    return 0;
}
