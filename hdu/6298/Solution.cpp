#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        ll n;
        scanf("%I64d",&n);
        if(n%3==0) cout<<n*n*n/27<<endl;
        else if(n%4==0)cout<<n*n*n/32<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
