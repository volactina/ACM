#include <bits/stdc++.h>
#define MAXLEN 50010

using namespace std;

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

void kmp(char s1[],char s2[]){
    int len1=strlen(s1),len2=strlen(s2),next[MAXLEN];
    cal_next(s1,len1,next);
    int j=0;
    for (int i=0;i<len2;i++){
        while(s2[i]!=s1[j]){
            if(j==0) break;
            j=next[j-1];
        }
        if(s2[i]==s1[j]){
            j++;
        }
    }
    if(j>0){
        for(int i=0;i<j;i++) printf("%c",s1[i]);
        printf(" ");
    }
    printf("%d\n",j);
    return;
}

int main()
{
    char s1[MAXLEN],s2[MAXLEN];
    while(~scanf("%s%s",s1,s2)) kmp(s1,s2);
    return 0;
}
