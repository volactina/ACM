#include <bits/stdc++.h>
#define MAXN 110

using namespace std;

void cal_next(string s,int len,int next[]){
    next[0]=0;
    int i=1,j=0;
    while(i<len){
        if(s[i]==s[j]){
            next[i++]=(j++)+1;
            continue;
        }
        while(s[i]!=s[j]){
            if(j==0){
                next[i++]=0;
                break;
            }
            j=next[j-1];
        }
    }
    return;
}

bool kmp(string pattern,string s){
    int lenp=pattern.size(),lens=s.size(),next[MAXN];
    cal_next(pattern,lenp,next);
    int j=0;
    for (int i=0;i<lens;i++){
        while(s[i]!=pattern[j]){
            if(j==0) break;
            j=next[j-1];
        }
        if(s[i]==pattern[j]){
            j++;
            if(j==lenp) return true;
        }
    }
    return false;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        string s[MAXN];
        scanf("%d",&n);
        for (int i=0;i<n;i++) cin>>s[i];
        int len=s[0].size();
        bool found=false;
        for (int nowlen=len;nowlen>=1;nowlen--){
            for (int i=0;i+nowlen-1<len;i++){
                string pattern1=s[0].substr(i,nowlen),pattern2=pattern1;
                reverse(pattern2.begin(),pattern2.end());
                found=true;
                for(int j=1;j<n;j++){
                    if(!kmp(pattern1,s[j])&&!kmp(pattern2,s[j])){
                        found=false;
                        break;
                    }
                }
                if(found) break;
            }
            if(found){
                printf("%d\n",nowlen);
                break;
            }
        }
        if(!found) printf("0\n");
    }
    return 0;
}
