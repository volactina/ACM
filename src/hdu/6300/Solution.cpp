#include <bits/stdc++.h>
#define MAXN 1010

using namespace std;

struct node{
    int id,x,y;
}point[MAXN<<2];

bool cmp(node x,node y){
    return x.x<y.x;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for (int i=1;i<=3*n;i++){
            scanf("%d%d",&point[i].x,&point[i].y);
            point[i].id=i;
        }
        sort(point+1,point+1+3*n,cmp);
        for (int i=1;i<=n;i++){
            printf("%d %d %d\n",point[3*i-2].id,point[3*i-1].id,point[3*i].id);
        }
    }
    return 0;
}
