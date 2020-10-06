#include <bits/stdc++.h>
#define MAXLEN 100010

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

void kmp(char con[],char s[]){
    int len=strlen(s),next[MAXLEN];
    printf("%s",s);
    int lens=(len+1)/2;
    for(int i=0;i<lens;i++) s[i]=con[s[i]-'a'];
    cal_next(s,lens,next);
    int j=0;
    for(int i=lens;i<len;i++){
        while(s[i]!=s[j]){
            if(j==0) break;
            j=next[j-1];
        }
        if(s[i]==s[j]) j++;
    }
    for(int i=j;i<j+(len-2*j);i++){
        if(i<lens) printf("%c",s[i]);else printf("%c",con[s[i]-'a']);
    }
    printf("\n");
    return;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        char conversion[30],s[MAXLEN],con[30];
        scanf("%s%s",conversion,s);
        memset(con,0,sizeof(con));
        for(int i=0;i<26;i++){
            con[conversion[i]-'a']='a'+i;
        }
        kmp(con,s);
    }
    return 0;
}
