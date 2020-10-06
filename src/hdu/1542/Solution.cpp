#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 110

using namespace std;

struct node{
    int id,fs,ft;
    double x,y;
}dot[MAXN<<2];
typedef struct node node;

bool cmp_x(node x,node y){return x.x<y.x;}
bool cmp_y(node x,node y){return x.y<y.y;}
bool cmp_id(node x,node y){return x.id<y.id;}

int main()
{
    int n,testcase=1,cnt[MAXN<<2];
    double ans,totx,lasty,f[MAXN<<2];
    while (~scanf("%d",&n)&&n){
        for (int i=1;i<=n;i++){
            dot[2*i-1].id=2*i-1,dot[2*i].id=2*i;
            scanf("%lf%lf%lf%lf",&dot[2*i-1].x,&dot[2*i-1].y,&dot[2*i].x,&dot[2*i].y);
        }
        sort(dot+1,dot+2*n+1,cmp_x);
        for (int i=1;i<=2*n;i++){
            if (dot[i].id%2==1) dot[i].fs=i; else dot[i].ft=i;
            if(i<2*n) f[i]=dot[i+1].x-dot[i].x;
        }
        sort(dot+1,dot+2*n+1,cmp_id);
        for (int i=1;i<=2*n;i++){
            if (dot[i].id%2==1) dot[i].ft=dot[i+1].ft;else dot[i].fs=dot[i-1].fs;
        }
        sort(dot+1,dot+2*n+1,cmp_y);
        ans=totx=lasty=0;
        memset(cnt,0,sizeof(cnt));
        for (int i=1;i<=2*n;i++){
            ans+=totx*(dot[i].y-lasty);
            lasty=dot[i].y;
            for (int j=dot[i].fs;j<dot[i].ft;j++){
                if (dot[i].id%2==0){
                    cnt[j]--;
                    if (cnt[j]==0) totx-=f[j];
                }else{
                    cnt[j]++;
                    if (cnt[j]==1) totx+=f[j];
                }
            }
        }
        printf("Test case #%d\nTotal explored area: %.2lf\n\n",testcase++,ans);
    }
    return 0;
}
