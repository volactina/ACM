#include <bits/stdc++.h>
#define MAXN 110

using namespace std;

int main()
{
    int dp[MAXN][MAXN],n,m;
    string s[MAXN][MAXN],a,b;
    while(cin>>a>>b){
        n=a.size(),m=b.size();
        memset(dp,0,sizeof(dp));
        s[0][0]="";
        for (int i=1;i<=n;i++) s[i][0]=s[i-1][0]+a[i-1];
        for (int j=1;j<=m;j++) s[0][j]=s[0][j-1]+b[j-1];
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                char cha=a[i-1],chb=b[j-1];
                if(cha==chb){
                    dp[i][j]=dp[i-1][j-1]+1;
                    s[i][j]=s[i-1][j-1]+cha;
                }else{
                    if(dp[i-1][j]>dp[i][j-1]){
                        dp[i][j]=dp[i-1][j];
                        s[i][j]=s[i-1][j]+cha;
                    }else{
                        dp[i][j]=dp[i][j-1];
                        s[i][j]=s[i][j-1]+chb;
                    }
                }
            }
        }
        cout<<s[n][m]<<endl;
    }
    return 0;
}
