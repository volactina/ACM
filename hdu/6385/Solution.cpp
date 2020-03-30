#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        ll mx,my,n,ans=0;
        scanf("%I64d%I64d%I64d",&mx,&my,&n);
        for(int i=0;i<n;i++){
            ll x,y;
            scanf("%I64d%I64d",&x,&y);
            ans+=min(x,min(y,min(mx-x,my-y)));
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
