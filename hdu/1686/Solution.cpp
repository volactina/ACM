#include <bits/stdc++.h>
#define MAXLEN 1000010
#define random_debug false

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

int kmp(char a[],char b[],int lena,int lenb,int next[]){
    b[lenb++]='#',b[lenb]='\0';
    cal_next(b,lenb,next);
    int cnt=0,j=0;
    for (int i=0;i<lena;i++){
        while(a[i]!=b[j]){
            if(j==0) break;
            j=next[j-1];
        }
        if(a[i]==b[j]){
            j++;
            if(j==lenb-1) cnt++;
            continue;
        }
    }
    return cnt;
}

int main(){
    if(random_debug){
        int debug_case=10000;
        srand((unsigned)time(NULL));
        while(debug_case--){
            int lenamin=1,lenamax=1000,lena,lenbmin=1,lenbmax=10,lenb,chmin='A',chmax='Z',next[MAXLEN];
            lena=rand()%(lenamax-lenamin+1)+lenamin,lenb=rand()%(lenbmax-lenbmin+1)+lenbmin;
            char a[MAXLEN],b[MAXLEN];
            for (int i=0;i<lena;i++) a[i]=rand()%(chmax-chmin+1)+chmin;
            for (int i=0;i<lenb;i++) b[i]=rand()%(chmax-chmin+1)+chmin;
            int ans1=0,ans2=kmp(a,b,lena,lenb,next);
            for(int i=0;i<lena;i++){
                bool check=true;
                for(int j=0;j<lenb;j++){
                    if(i+j>=lena){
                        check=false;
                        break;
                    }
                    if(a[i+j]!=b[j]){
                        check=false;
                        break;
                    }
                }
                if(check) ans1++;
            }
            if(ans1!=ans2){
                printf("a:%d %s\nb:%d %s\nans1=%d,ans2=%d\nnext:",lena,a,lenb,b,ans1,ans2);
                for(int i=0;i<lenb;i++) printf("%d ",next[i]);
                printf("\n");
                return 0;
            }
            if(ans1>1&&lenb>1) printf("%d %d %d\n",ans1,lena,lenb);
        }
        printf("correct\n");
        return 0;
    }
    int t;
    scanf("%d",&t);
    while(t--){
        char a[MAXLEN],b[MAXLEN];
        scanf("%s%s",b,a);
        int next[MAXLEN],lena=strlen(a),lenb=strlen(b);
        printf("%d\n",kmp(a,b,lena,lenb,next));
    }
    return 0;
}
