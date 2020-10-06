#include <bits/stdc++.h>
#define MAXLEN 100010

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
    return;
}

bool kmp(char s1[],char s2[],int len1,int len2){
    int *next=new int[len2];
    strncpy(s1+len1,s1,len1+1);
    len1=strlen(s1);
    cal_next(s2,len2,next);
    int j=0;
    for (int i=0;i<len1;i++){
        while(s1[i]!=s2[j]){
            if(j==0) break;
            j=next[j-1];
        }
        if(s1[i]==s2[j]){
            j++;
            if(j==len2) return true;
        }
    }
    return false;
}

int main()
{
    char *s1=new char[MAXLEN<<1],*s2=new char[MAXLEN];
    while(~scanf("%s%s",s1,s2)){
        int len1=strlen(s1),len2=strlen(s2);
        if(kmp(s1,s2,len1,len2)) printf("yes\n");else printf("no\n");
    }
    return 0;
}
