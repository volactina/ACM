#include <bits/stdc++.h>

using namespace std;

const int MAXLEN=1e5+10;
void cal_next(char s[],int len,int next[]){
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
int kmp(char s[]){
    int len=strlen(s),next[MAXLEN];
    cal_next(s,len,next);
    int j=0;
    for(int i=1;i<len;i++){
        while(s[i]!=s[j]){
            if(j==0) break;
            j=next[j-1];
        }
        if(s[i]==s[j]){
            j++;
        }
    }
    int unit=len-j;
    if(unit==len) return len;
    char s1[MAXLEN],s2[MAXLEN];
    strncpy(s1,s,unit),strncpy(s2,s+j,unit);
    if(strcmp(s1,s2)==0) return 0;
    return unit-len%unit;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        char s[MAXLEN];
        scanf("%s",s);
        printf("%d\n",kmp(s));
    }
    return 0;
}
