#ifdef unix
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif
#define SCANFLL(x) scanf(LLD,&x)
#define PRINTLL(x) printf(LLD,x),printf("\n")
#include <bits/stdc++.h>
#define MAXN 100010
#define ll long long

using namespace std;
const ll MODN=1000000007ll;
//O(n)预处理阶乘逆元,O(1)计算组合数
ll fac[MAXN],invfac[MAXN];
ll inv(ll x){
    ll cnt=MODN-2ll,base=x,ans=1ll;
    while(cnt){
        if(cnt&1ll) ans=(ans*base)%MODN;
        base=(base*base)%MODN;
        cnt>>=1;
    }
    return ans;
}
void init_fac(){
    fac[0]=fac[1]=1ll;
    for(ll i=2ll;i<MAXN;i++) fac[i]=(fac[i-1]*i)%MODN;
    invfac[MAXN-1]=inv(fac[MAXN-1]);
    for(ll i=MAXN-2;i>=0;i--) invfac[i]=(invfac[i+1]*(i+1ll))%MODN;
    return;
}
ll C(ll n,ll m){
    return (((fac[n]*invfac[m])%MODN)*invfac[n-m])%MODN;
}
//莫队算法,离线处理查询
struct node{
    ll n,m,id,blk;
}Q[MAXN];
bool cmp(node x,node y){
    if(x.blk==y.blk) return x.n<y.n;
    return x.blk<y.blk;
}
ll nowm,nown,nowans,inv2=inv(2ll);
void addn(){
    nowans=((2ll*nowans)%MODN-C(nown,nowm)+MODN)%MODN;
    return;
}
void minusn(){
    nowans=(((nowans+C(nown,nowm))%MODN)*inv2)%MODN;
    return;
}
void addm(){
    nowans=(nowans+C(nown,nowm))%MODN;
    return;
}
void minusm(){
    nowans=(nowans-C(nown,nowm)+MODN)%MODN;
    return;
}

int main()
{
    init_fac();
    ll ans[MAXN],t,sz;
    SCANFLL(t);
    sz=sqrt(t);
for(ll i=0;i<t;i++){
 SCANFLL(Q[i].n),SCANFLL(Q[i].m),Q[i].id=i,Q[i].blk=Q[i].m/sz;
}
    sort(Q,Q+t,cmp);
    nowm=nown=0,nowans=1ll;
    for(ll i=0;i<t;i++){
        while(nown<Q[i].n) addn(),nown++;
        while(nown>Q[i].n) nown--,minusn();
        while(nowm<Q[i].m) nowm++,addm();
        while(nowm>Q[i].m) minusm(),nowm--;
        ans[Q[i].id]=nowans;
    }
    for(ll i=0;i<t;i++) PRINTLL(ans[i]);
    return 0;
}
