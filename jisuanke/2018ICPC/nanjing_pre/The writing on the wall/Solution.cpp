#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010
#define MAXM 110

using namespace std;

ll n,m,k,b[MAXN][MAXM],up[MAXN];

int main()
{
    int t;
    scanf("%d",&t);
    for(int casenum=1;casenum<=t;casenum++){
        ll ans=0;
        cin>>n>>m>>k;
        memset(b,0,sizeof(b));
        for(int i=0;i<k;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            b[x][y]=1;
        }
        for(int i=1;i<=m;i++){
            up[i]=n+1;
            for(int j=1;j<=n;j++){
                if(b[j][i]){
                    up[i]=j;
                    break;
                }
            }
        }
        for(int j=1;j<=n;j++){
            for(int i=1;i<=m;i++){
                if(b[j][i]) continue;
                ll h=n-j+1;
                for(int k=i;k<=m;k++){
                    if(up[k]<j){
                        up[k]=n+1;
                        for(int tmp=j;tmp<=n;tmp++){
                            if(b[tmp][k]){
                                up[k]=tmp;
                                break;
                            }
                        }
                    }
                    if(up[k]==j){
                        break;
                    }
                    h=min(h,up[k]-j);
                    ans+=h;
                }
            }
        }
        cout<<"Case #"<<casenum<<": "<<ans<<endl;
    }
    return 0;
}