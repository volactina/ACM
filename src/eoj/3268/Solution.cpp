#include <bits/stdc++.h>
#define ll long long
#define MAXN 110

using namespace std;

int main()
{
    ll n,m,images[MAXN][MAXN],h,w,kernel[MAXN][MAXN];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>images[i][j];
        }
    }
    cin>>h>>w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>kernel[i][j];
        }
    }
    for(int i=0;i+h-1<n;i++){
        for(int j=0;j+w-1<m;j++){
            int ans=0;
            for(int ii=i;ii<i+h;ii++){
                for(int jj=j;jj<j+w;jj++){
                    ans+=images[ii][jj]*kernel[ii-i][jj-j];
                }
            }
            cout<<ans;
            if(j+w-1==m-1) cout<<endl;else cout<<" ";
        }
    }
    return 0;
}
