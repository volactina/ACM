#include <bits/stdc++.h>
#define MAXLEN 505

using namespace std;

bool check(char s[]){
    int len=strlen(s);
    for(int i=0;i<len;i++){

    }
    return true;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        char s[MAXLEN];
        scanf("%s",s);
        const int OPERATOR=111,NUM_NOT_ZERO=112,ZERO=113,NONE=114;
        bool pre_zero=false,valid=true;
        int len=strlen(s),last_type=NONE;
        for(int i=0;i<len;i++){
            if(s[i]=='0'){
                if(pre_zero){
                    valid=false;
                    break;
                }
                if(last_type!=NUM_NOT_ZERO&&last_type!=ZERO){
                    pre_zero=true;
                }
                last_type=ZERO;
            }
            else if(s[i]>='1'&&s[i]<='9'){
                if(pre_zero){
                    valid=false;
                    break;
                }
                last_type=NUM_NOT_ZERO;
                pre_zero=false;
            }
            else if(s[i]=='+'||s[i]=='*'){
                if(last_type==OPERATOR||i==len-1||i==0){
                    valid=false;
                    break;
                }
                last_type=OPERATOR;
                pre_zero=false;
            }else if(s[i]=='?'){
                if(pre_zero){
                    if(i==len-1){
                        valid=false;
                        break;
                    }
                    s[i]='+';
                    last_type=OPERATOR;
                    pre_zero=false;
                }else{
                    s[i]='1';
                    last_type=NUM_NOT_ZERO;
                    pre_zero=false;
                }
            }
        }
        if(!valid) printf("IMPOSSIBLE\n");else printf("%s\n",s);
    }
    return 0;
}
