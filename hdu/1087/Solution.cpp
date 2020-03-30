#include <bits/stdc++.h>
#define MAXN 1010

using namespace std;

int main()
{
    int n,num[MAXN],dp[MAXN],maxans;
    while(cin>>n&&n){
        memset(dp,0,sizeof(dp)),maxans=0;
        for (int i=0;i<n;i++){
            cin>>num[i];
            for (int j=i-1;j>=0;j--) if(num[j]<num[i]&&dp[j]>dp[i]) dp[i]=dp[j];
            dp[i]+=num[i],maxans=max(maxans,dp[i]);
        }
        cout<<maxans<<endl;
    }
    return 0;
}
