#include <bits/stdc++.h>
#define MAXLEN 210
#define MAXM 4004

using namespace std;

void cal_next(char s[],int len,int next[]){
    next[0]=0;
    int j=0,i=1;
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
}

bool kmp(char pattern[],int len,char s[]){
    int next[MAXLEN];
    cal_next(pattern,len,next);
    int j=0,lens=strlen(s);
    for (int i=0;i<lens;i++){
        while(s[i]!=pattern[j]){
            if(j==0) break;
            j=next[j-1];
        }
        if(s[i]==pattern[j]){
            j++;
            if(j==len) return true;
        }
    }
    return false;
}

int main()
{
    int m;
    while(~scanf("%d",&m)&&m){
        char s[MAXM][MAXLEN];
        scanf("%d",&m);
        for(int i=0;i<m;i++) scanf("%s",s[i]);
        bool found=false;
        int s0len=strlen(s[0]);
        for (int len=s0len;len>=1;len--){
            char ans[MAXLEN];
            bool first=true;
            for(int i=0;i+len-1<s0len;i++){
                found=true;
                for(int j=1;j<m;j++){
                    if(!kmp(s[0]+i,len,s[j])){
                        found=false;
                        break;
                    }
                }
                if(found){
                    if(first){
                        first=false;
                        strncpy(ans,s[0]+i,len),ans[len]='\0';
                    }else{
                        char temp[MAXLEN];
                        strncpy(temp,s[0]+i,len),temp[len]='\0';
                        if(strcmp(temp,ans)<0) strncpy(ans,temp,len);
                    }
                }
            }
            if(!first){
                found=true,printf("%s\n",ans);
                break;
            }
        }
        if(!found) printf("IDENTITY LOST\n");
    }
    return 0;
}
