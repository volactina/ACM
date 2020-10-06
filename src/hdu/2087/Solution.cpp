#include <bits/stdc++.h>
#define MAXN 1010
#define random_debug false

using namespace std;

void cal_next(char s[],int len,int next[]){
    next[0]=0;
    int i=1,j=0;
    while(i<len){
        if(s[i]==s[j]){
            next[i]=j+1,i++,j++;
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

int kmp(char a[],char b[],int lena,int lenb,int next[]){
    cal_next(b,lenb,next);
    int cnt=0;
    int j=0;
    for (int i=0;i<lena;i++){
        while(a[i]!=b[j]){
            if(j==0) break;
            j=next[j-1];
        }
        if(a[i]==b[j]){
            j++;
            if(j==lenb){
                cnt++;
                j=0;
            }
        }
    }
    return cnt;
}

int main(){
    if(random_debug){
        srand((unsigned)time(NULL));
        int debugcase=1000;
        while(debugcase--){
            char a[MAXN],b[MAXN],chmin='a',chmax='d';
            int lenamin=1,lenamax=1000,lena=rand()%(lenamax-lenamin+1)+lenamin,lenbmin=1,lenbmax=100,lenb=rand()%(lenbmax-lenbmin+1)+lenbmin,next[MAXN];
            for(int i=0;i<lena;i++) a[i]=rand()%(chmax-chmin+1)+chmin;
            for(int i=0;i<lenb;i++) b[i]=rand()%(chmax-chmin+1)+chmin;
            a[lena]=b[lenb]='\0';
            int ans1=0,ans2=kmp(a,b,lena,lenb,next);
            int i=0;
            while(i<lena){
                bool match=true;
                int j;
                for(j=0;j<lenb;j++){
                    if(i+j>=lena){
                        match=false;
                        break;
                    }
                    if(a[i+j]!=b[j]){
                        match=false;
                        break;
                    }
                }
                if(match){
                    ans1++,i=i+j;
                }else{
                    i++;
                }
            }
            if(ans1!=ans2){
                printf("error\na:%s\nb:%s\nans1:%d,ans2:%d\n",a,b,ans1,ans2);
                return 0;
            }
            //if(ans1>0&&lenb>1) printf("a:%s\nb:%s\nans1:%d,ans2:%d\n",a,b,ans1,ans2);
        }
        printf("correct\n");
        return 0;
    }
    char a[MAXN],b[MAXN];
    int lena,lenb,next[MAXN];
    while(~scanf("%s",a)){
        if(a[0]=='#'&&strlen(a)==1) break;
        scanf("%s",b);
        lena=strlen(a),lenb=strlen(b);
        printf("%d\n",kmp(a,b,lena,lenb,next));
    }
    return 0;
}
