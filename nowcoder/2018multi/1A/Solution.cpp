#include <bits/stdc++.h>
#define MAXN 3010
#define ll long long
#define N 1000000007

using namespace std;
//逆元
ll inv(ll x,ll mod)
{
    ll k=mod-2,ans=1;
    while(k)
    {
        if (k&1) ans=(ans*x)%mod;
        x=(x*x)%mod;
        k>>=1;
    }
    return ans;
}
//组合数&记忆化搜索
ll rc[MAXN][MAXN];
ll c(int n,int m){
    if(rc[n][m]>=0) return rc[n][m];
    if(n==m) return rc[n][m]=1;
    if(m==1||m==0) return rc[n][m]=n;
    return rc[n][m]=(c(n-1,m-1)+c(n-1,m))%N;
}
ll t(int n,int k){
    return (((c(n-1,k-1)*c(n,k-1))%N)*inv(k,N))%N;
}

int main(){
    memset(rc,-1,sizeof(rc)); 
    int n,m;
    while(cin>>n>>m) cout<<t(n+m+1,m+1)<<endl;
    return 0;
}
