#include <bits/stdc++.h>
#define MAXN 500010

using namespace std;

int n,k,a[MAXN],ans[MAXN];

int main()
{

    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);
    for(int i=0;i<n-k;i++) ans[i]=a[i];
    for(int i=n-k;i<n;i++) ans[2*n-k-1-i]=a[i];
    bool fit=true;
    int falsenum=0,truenum=0;
    for(int i=n-1;i>=0;i--){
        if(falsenum>=ans[i]) truenum++;else falsenum++;
    }
    if(falsenum!=k) fit=false;
    if(fit){
        for(int i=0;i<n;i++){
            printf("%d",ans[i]);
            if(i==n-1) printf("\n");else printf(" ");
        }
    }else{
        printf("-1\n");
    }
    return 0;
}
