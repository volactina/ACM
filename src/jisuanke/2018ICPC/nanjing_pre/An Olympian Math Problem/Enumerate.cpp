#include <bits/stdc++.h>

using namespace std;

int f(int x,int n){
    int ans=1;
    for(int i=1;i<=x;i++) ans=(ans*i)%n;
    return ans;
}

int main()
{
    int n;
    while(cin>>n){
        int ans=0;
        for(int i=1;i<=n-1;i++){
            ans=(ans+(i*f(i,n))%n)%n;
        }
        cout<<ans<<endl;
    }
    return 0;
}
