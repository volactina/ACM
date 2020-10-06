#include <bits/stdc++.h>
#define ll long long
#define MODN 1000000007
#define MAXN 10010

using namespace std;

int n,num[MAXN],dp[MAXN][1000],maxlen[MAXN];
void init(){
    for(int i=0;i<=n;i++) memset(dp[i],0,sizeof(dp[i]));
    memset(maxlen,0,sizeof(maxlen));
    return;
}
int lowbit(int x){return x&(-x);}
int query_sum(int x,int k){
    int ans=0;
    while(x){
        ans=(ans+dp[x][k])%MODN;
        x-=lowbit(x);
    }
    return ans;
}
void update_sum(int x,int k,int num){
    while(x<=n){
        dp[x][k]=(dp[x][k]+num)%MODN;
        x+=lowbit(x);
    }
    return;
}
int query_max(int x){
    int ans=0;
    while(x){
        ans=max(ans,maxlen[x]);
        x-=lowbit(x);
    }
    return ans;
}
void update_max(int x,int num){
    while(x<=n){
        maxlen[x]=max(maxlen[x],num);
        x+=lowbit(x);
    }
    return;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int casenum=1;casenum<=t;casenum++){
        init();
        scanf("%d",&n);
        int ans[MAXN];
        memset(ans,0,sizeof(ans));
        for(int i=1;i<=n;i++){
            scanf("%d",&num[i]);
            int nowmaxlen=query_max(num[i]-1)+1,temp[MAXN];
            update_max(num[i],nowmaxlen);
            ans[1]=(ans[1]+1)%MODN;
            update_sum(num[i],1,1);
            for(int j=2;j<=nowmaxlen;j++){
                temp[j]=query_sum(num[i]-1,j-1);
                ans[j]=(ans[j]+temp[j])%MODN;
                update_sum(num[i],j,temp[j]);
            }
        }
        printf("Case #%d:",casenum);
        for(int i=1;i<=n;i++) printf(" %d",ans[i]);
        printf("\n");
    }
    return 0;
}
