#include <bits/stdc++.h>
#define MAXN 100010
#define MAXM 10010
#define random_debug false

using namespace std;

void cal_next(int n,int num[],int next[]){
    next[0]=0;
    int i=1,j=0;
    while(i<n){
        if(num[i]==num[j]){
            next[i]=j+1,i++,j++;
            continue;
        }
        while(num[i]!=num[j]){
            if(j==0){
                next[i++]=0;
                break;
            }
            j=next[j-1];
        }
    }
    return;
}

int kmp(int n,int m,int s[],int pattern[],int next[]){
    cal_next(m,pattern,next);
    int j=0;
    for (int i=0;i<n;i++){
        while(s[i]!=pattern[j]){
            if(j==0) break;
            j=next[j-1];
        }
        if(s[i]==pattern[j]) j++;
        if(j==m) return i-m+2;
    }
    return -1;
}

int main()
{
    if(random_debug){
        int checktime=100000;
        srand((unsigned)time(NULL));//这个必须放在外面才能在while语句内每次生成随机的序列
        while(checktime--){
            int nmin=1,nmax=1000,mmin=1,mmax=1000,a[MAXN],b[MAXM],nummin=-3,nummax=3,next[MAXM];
            int n=rand()%(nmax-nmin+1)+nmin,m=rand()%(mmax-mmin+1)+mmin;
            for(int i=0;i<n;i++) a[i]=rand()%(nummax-nummin+1)+nummin;
            for(int i=0;i<m;i++) b[i]=rand()%(nummax-nummin+1)+nummin;
            int ans1=-1,ans2=kmp(n,m,a,b,next);
            for(int i=0;i<n;i++){
                bool found=true;
                for (int j=0;j<m;j++){
                    if(i+j>=n){
                        found=false;
                        break;
                    }
                    if(a[i+j]!=b[j]){
                        found=false;
                        break;
                    }
                }
                if(found){
                    ans1=i+1;
                    break;
                }
            }
            if(ans1!=ans2){
                printf("error\na:");
                for (int i=0;i<n;i++) printf("%d ",a[i]);
                printf("\nb:");
                for (int i=0;i<m;i++) printf("%d ",b[i]);
                printf("\nnext:");
                for (int i=0;i<m;i++) printf("%d ",next[i]);
                printf("ans1:%d,ans2:%d\n",ans1,ans2);
                return 0;
            }
            if(ans1!=-1) printf("%d %d %d\n",n,m,ans1);
        }
        printf("correct\n");
        return 0;
    }
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,a[MAXN],b[MAXM],next[MAXM];
        scanf("%d%d",&n,&m);
        for (int i=0;i<n;i++) scanf("%d",&a[i]);
        for (int i=0;i<m;i++) scanf("%d",&b[i]);
        printf("%d\n",kmp(n,m,a,b,next));
    }
    return 0;
}
