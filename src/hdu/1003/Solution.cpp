#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    for(int casenum=1;casenum<=t;casenum++){
        int n,maxsum=INT_MIN,nowsum=-1,maxfirst=0,maxlast=0,nowfirst=1,nownum;
        scanf("%d",&n);
        for (int i=1;i<=n;i++){
            scanf("%d",&nownum);
            if(nowsum<0) nowsum=nownum,nowfirst=i;else nowsum+=nownum;
            if(nowsum>maxsum) maxsum=nowsum,maxfirst=nowfirst,maxlast=i;
        }
        printf("Case %d:\n%d %d %d\n",casenum,maxsum,maxfirst,maxlast);
        if(casenum!=t) printf("\n");
    }
    return 0;
}
