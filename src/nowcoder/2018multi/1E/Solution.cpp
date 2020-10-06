#include <bits/stdc++.h>
#define MAXN 10010
#define N 1000000007
#define MAXK 15
#define ll long long

using namespace std;

int main()
{
    int n,m,k,dp[MAXN][MAXK],sum[MAXN],num[MAXN];
    while(~scanf("%d%d%d",&n,&m,&k)){
        for (int i=1;i<=n;i++) scanf("%d",&num[i]);
        memset(dp,0,sizeof(dp)),memset(sum,0,sizeof(sum)),sum[0]=1;
        for (int i=1;i<=n;i++){
            for (int j=i;j>=max(1,i-m);j--){
                int change=(sum[j-1]-dp[j][num[i]]+N)%N;
                dp[j][num[i]]=sum[j-1];
                sum[j]=(sum[j]+change)%N;
            }
        }
        printf("%d\n",sum[n-m]);
    }
    return 0;
}
