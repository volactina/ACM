#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;

int main()
{
    int t,n,q;
    int **sum=new int*[26];
    for(int i=0;i<26;i++) sum[i]=new int[MAXN];
    char *s=new char[MAXN];
    scanf("%d",&t);
    for(int casenum=1;casenum<=t;casenum++){
        scanf("%d%d",&n,&q);
        for(int i=0;i<26;i++) for(int j=0;j<MAXN;j++) sum[i][j]=0;
        scanf("%s",s);
        for(int i=0;i<n;i++){
            if(i){
                for(int j=0;j<26;j++) sum[j][i]=sum[j][i-1];
            }
            sum[s[i]-'A'][i]++;
        }
        printf("Case #%d:\n",casenum);
        while(q--){
            int l,r;
            scanf("%d%d",&l,&r);
            l--,r--;
            for(int j=0;j<26;j++){
                int ans=(l==0)?sum[j][r]:sum[j][r]-sum[j][l-1];
                if(ans){
                    printf("%d\n",ans);
                    break;
                }
            }
        }
    }
    delete[] s;
    return 0;
}
