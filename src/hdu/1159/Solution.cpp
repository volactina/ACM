#include <bits/stdc++.h>
#define MAXN 1010

using namespace std;

int main()
{
    string sa,sb;
    int n,m,dp[MAXN][MAXN];
    while(cin>>sa>>sb){
        n=sa.size(),m=sb.size(),memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                char a=sa[i-1],b=sb[j-1];
                if(a==b) dp[i][j]=dp[i-1][j-1]+1;
else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        printf("%d\n",dp[n][m]);
    }
    return 0;
}
