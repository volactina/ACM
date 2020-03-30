#include <bits/stdc++.h>
#define MAXN 1010

using namespace std;

int fast_pow(int x,int n){
    int ans=1,base=x;
    while(n){
        if(n&1) ans*=base;
        base*=base;
        n>>=1;
    }
    return ans;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int casenum=1;casenum<=t;casenum++){
        int n,m,k,ans=0;
        char s[MAXN][20];
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0;i<n;i++) scanf("%s",s[i]);
        int choicenum=fast_pow(2,m);
        for(int choice=1;choice<choicenum;choice++){
            map<int,int> cnt;
            cnt.clear();
            int cntsz=0;
            bool found=false;
            for(int i=0;i<n;i++){
                int result=0,base=1,tmp=choice,nows=0;
                while(tmp){
                    if(tmp&1){
                        if(s[i][nows]=='B') result+=base;
                        base*=2;
                    }
                    nows++;
                    tmp>>=1;
                }
                if(cnt.find(result)==cnt.end()) cnt[result]=1,cntsz++;else cnt[result]++;
                if(cntsz*(cntsz-1)/2>=k){
                    found=true;
                    break;
                }
            }
            if(found){
                ans++;
            }else{
                int a=0,b=0;
                for(map<int,int>::iterator it=cnt.begin();it!=cnt.end();it++){
                    a+=it->second;
                    b+=(it->second)*(it->second);
                }
                if((a*a-b)/2>=k) ans++;
            }
        }
        printf("Case #%d: %d\n",casenum,ans);
    }
    return 0;
}
