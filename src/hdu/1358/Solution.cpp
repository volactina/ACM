#include <bits/stdc++.h>
#define MAXLEN 1000010

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
void kmp(char s[],int len){
    int next[MAXLEN];
    cal_next(s,len,next);
    for (int i=1;i<len;i++){
        if((i+1)%(i-next[i]+1)==0&&next[i]!=0){
            printf("%d %d\n",i+1,(i+1)/(i-next[i-1]));
        }
    }
    return;
}

int main()
{
    int len,casenum=1;
    char s[MAXLEN];
    while(~scanf("%d",&len)&&len){
        scanf("%s",s);
        printf("Test case #%d\n",casenum++);
        kmp(s,len);
        printf("\n");
    }
    return 0;
}
