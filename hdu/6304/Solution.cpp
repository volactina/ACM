#include <bits/stdc++.h>
#define ll long long
#define MAXN 100
#define MODN 1000000007
using namespace std;

ll fast_pow(ll a,ll b,ll N,bool modflag){
    if(modflag){
        a%=N;
        ll base=a,ans=1;
        while(b){
            if(b&1) ans=(ans*base)%N;
            b>>=1;
            base=(base*base)%N;
        }
        return ans;
    }
    ll base=a,ans=1;
    while(b){
        if(b&1) ans*=base;
        b>>=1;
        base*=base;
    }
    return ans;

}

ll f(ll n){
    if(n==1) return 4;
    return (3*fast_pow(2,2*(n-1),MODN,true))%MODN+((n+1)*fast_pow(2,n-2,MODN,true))%MODN;
}

ll s[MAXN]={1,2};
int main(){
    for (int i=2;i<=70;i++){
        s[i]=(s[i-1]+f(i-1)%MODN)%MODN;
    }
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(n==1){
            cout<<1<<endl;
            continue;
        }
        int cnt=0;
        while(fast_pow(2,cnt,MODN,false)<=n) cnt++;
        cnt--;
        ll ans=s[cnt];
        n=n-fast_pow(2,cnt,MODN,false);
        while(n){
            n++;
            ll add=(fast_pow(2,cnt-1,MODN,false))%MODN;
            ans=(ans+((add*((n-1)%MODN))%MODN))%MODN;
            while(fast_pow(2,cnt,MODN,false)>n) cnt--;
            ans=((ans+s[cnt])%MODN+MODN-1)%MODN;
            n=n-fast_pow(2,cnt,MODN,false);
        }
        cout<<ans<<endl;
    }
    return 0;
}
