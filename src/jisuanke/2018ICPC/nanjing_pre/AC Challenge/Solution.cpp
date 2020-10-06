#include <bits/stdc++.h>
#define ll long long
#define MAXN 30
using namespace std;
int lessonnum,pre[MAXN];
ll myans=0,a[MAXN],b[MAXN],dp[1<<20];
int lowbit(int x){return x&(-x);}
int count_1(int x){
    int cnt=0;
    while(x) x-=lowbit(x),cnt++;
    return cnt;
}
int main(){
    scanf("%d",&lessonnum);
    memset(pre,0,sizeof(pre));
    for(int i=1;i<=lessonnum;i++){
        cin>>a[i]>>b[i];
        int prenum;
        scanf("%d",&prenum);
        for(int j=0;j<prenum;j++){
            int tmp;
            scanf("%d",&tmp);
            pre[i]+=1<<(tmp-1);
        }
    }
    memset(dp,-1,sizeof(dp)),dp[0]=0;
    for(int i=1;i<(1<<lessonnum);i++){
        for(int j=1;j<=lessonnum;j++){
            if(i&(1<<(j-1))){//枚举子集
                int tmp=i-(1<<(j-1));
                if((tmp&pre[j])==pre[j]){//是否符合转移条件
                    if(dp[tmp]!=-1){
                        dp[i]=max(dp[i],dp[tmp]+count_1(i)*a[j]+b[j]);
                    }
                }
            }
        }
        myans=max(myans,dp[i]);
    }
    cout<<myans<<endl;
    return 0;
}
