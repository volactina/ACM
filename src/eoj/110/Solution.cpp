#include <bits/stdc++.h>
#define ll long long
#define MAXN 300010

using namespace std;

int main(){
    ll n,k,a[MAXN],b[MAXN];
    scanf("%lld%lld",&n,&k);
    for(ll i=0;i<n;i++){
        scanf("%lld",&a[i]);
        a[i]-=i*k;//每个数减去它所要求的公差后应该要相等(这样把这个公差加回去之后就是它所要的等差数列)
    }
    /*
        找到a数组的中位数
    */
    memcpy(b,a,sizeof(a));
    sort(b,b+n);
    ll mid=b[n/2];
    if(mid<0) mid=0;//特判中位数<0的情况，因为蝌蚪数不能为负
    ll ans=0;
    /*计算操作数*/
    for (int i=0;i<n;i++) ans+=(a[i]>mid)?a[i]-mid:mid-a[i];
    cout<<ans<<endl;
    return 0;
} 
