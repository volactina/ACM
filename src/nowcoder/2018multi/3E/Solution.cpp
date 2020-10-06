#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+100;
char s[maxn];
int Next[maxn];

void cal_next()
{
    int k;
    Next[0] = k = -1;
    int len = strlen(s);
    for(int i=1;i<len;i++)
    {
        while(k>-1 && s[i] != s[k+1])
            k = Next[k];
        if(s[i] == s[k+1])
            k++;
        Next[i] = k;
    }
}

int main()
{
    int groupnum,groupsize;
    scanf("%s",s);
    cal_next();
    int len = strlen(s);
    if(len%(len - Next[len-1] - 1) == 0) groupsize=len/(len - Next[len-1] - 1); else groupsize=1;
    groupnum=len/groupsize;
    //cout<<"groupnum:"<<groupnum<<endl;
    //cout<<"groupsize:"<<groupsize<<endl;
    printf("%d\n",groupnum);
    for(int i=0;i<groupnum;i++){
        printf("%d ",groupsize);
        for (int j=0;j<groupsize;j++){
            printf("%d",i+j*groupnum);
            if(j==groupsize-1) printf("\n");else printf(" ");
        }
    }
    return 0;
}
