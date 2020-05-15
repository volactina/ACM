#include <bits/stdc++.h>
#define MAXN 3010
#define ll long lon

ll n,m,cnt;
int num[MAXN][MAXN];
void dfs(int x,int y){
    for (int i=max(num[x-1][y],num[x][y-1]);i<=2;i++){
        num[x][y]=i;
        if(y<m) dfs(x,y+1); else if(x<n) dfs(x+1,1); else cnt++;
    }
    return;
}

int main()
{
    int maxn,maxm;
    cin>>maxn>>maxm;
    for (int i=1;i<=maxn;i++){
        for (int j=1;j<=maxm;j++){
            n=i,m=j;
            memset(num,0,sizeof(num));
            cnt=0;
            dfs(1,1);
            cout<<cnt<<" ";
        }
        cout<<endl;
    }
    return 0;
}
