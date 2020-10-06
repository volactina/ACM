#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        ll k;
        cin>>k;
        k*=2;
        ll b=sqrt(k)+1;
        for(;b>=1;b--){
            if(k%b==0&&(b<=(k/b))){
                ll a=k/b;
                if((a+b-1)%2==0&&(a-b+1)%2==0){
                    ll t=(a+b-1)/2,s=(a-b+1)/2;
                    cout<<s<<" "<<t<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}
