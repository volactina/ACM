#include <bits/stdc++.h>
#define MAXN 20
#define debug false
#define hugedebug false

using namespace std;

int dp[MAXN][10],digit[MAXN];
int solve(int x){
    memset(digit,0,sizeof(digit));
    int len=0,ans=0;
    while(x){
        digit[len++]=x%10;
        x/=10;
    }
    for(int i=len-1;i>=0;i--){
        for (int j=0;j<digit[i];j++){
            if(!(digit[i+1]==6&&j==2)) ans+=dp[i][j];
        }
        if(digit[i]==4) break;
        if(digit[i+1]==6&&digit[i]==2) break;
    }
    return ans;
}

int debug_print(int n,int m){
    int cnt=0;
    for (int i=n;i<=m;i++){
        char temp[20];
        sprintf(temp,"%d",i);
        bool check=true;
        for (int j=0;j<(int)strlen(temp);j++){
            if(temp[j]=='4'||((j+1<(int)strlen(temp))&&(temp[j]=='6'&&temp[j+1]=='2'))){
                check=false;
                break;
            }
        }
        if(check) cnt++;
    }
    if(!hugedebug) cout<<"ans="<<cnt<<endl;
    return cnt;
}

int main(){
    memset(dp,0,sizeof(dp));
    int lastsum,sum;
    for(int i=0;i<MAXN;i++){
        sum=0;
        for (int j=0;j<10;j++){
            if(i==0){
                if(j!=4) dp[i][j]=1;
            }else{
                if(j==4) continue;
                if(j!=6) dp[i][j]=lastsum;else dp[i][j]=lastsum-dp[i-1][2];
            }
            sum+=dp[i][j];
        }
        lastsum=sum;
    }
    if(hugedebug){
        int hugenum=1000;
        for (int n=1;n<=hugenum;n++){
            for (int m=n;m<=hugenum;m++){
                int ans1=debug_print(n,m),ans2=solve(m+1)-solve(n);
                if(ans1!=ans2){
                    cout<<n<<" "<<m<<endl;
                    cout<<"ans1:"<<ans1<<endl;
                    cout<<"ans2:"<<ans2<<endl;
                    return 0;
                }
            }
        }
        cout<<"correct"<<endl;
        return 0;
    }
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        if (n==0&&m==0) break;
        if(debug) debug_print(n,m);
        printf("%d\n",solve(m+1)-solve(n));
    }
    return 0;
}
