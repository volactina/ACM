#include <bits/stdc++.h>
#define MAXLEN 20
#define debugassert true
#define ASSERT(X) if(!(X)) while(true);

using namespace std;
bool cmp1(char x,char y){return x<y;}
bool cmp2(char x,char y){return x>y;}
bool find_max,find_min;
int len;
char ansmax[MAXLEN],ansmin[MAXLEN],smax[MAXLEN],smin[MAXLEN];
//得到s的理论最大值,存入smax
void get_max(const char s[]){
    strncpy(smax,s,len+1);
    sort(smax,smax+len,cmp2);
    return;
}
//得到s的理论最小值,存入smin
void get_min(const char s[]){
    strncpy(smin,s,len+1);
    sort(smin,smin+len,cmp1);
    for(int i=0;i<len;i++){
        if(smin[i]!='0'){
            swap(smin[0],smin[i]);
            return;
        }
    }
    return;
}
//返回第1个不相同的位置
int get_diff(const char s1[],const char s2[]){
    if(debugassert) ASSERT(strlen(s1)==strlen(s2));
    int i=0;
    while(i<len&&s1[i]==s2[i]) i++;
    return i;
}
const int INCLUDE_ZERO=1,EXCLUDE_ZERO=2;
//从start开始找到其最小的数字(含0/非0)
char minch(const char s[],int start,int flag){
    if(debugassert) ASSERT(start<strlen(s));
    char ch='9'+1;
    for(int i=start;i<len;i++){
        if(flag==INCLUDE_ZERO){
            ch=min(ch,s[i]);
        }else{
            if(s[i]=='0') continue;
            ch=min(ch,s[i]);
        }
    }
    if(debugassert) ASSERT(ch<='9');
    return ch;
}
//从start开始找到其最大的数字
char maxch(const char s[],int start){
    if(debugassert) ASSERT(start<strlen(s));
    char ch='0'-1;
    for(int i=start;i<len;i++){
        ch=max(ch,s[i]);
    }
    if(debugassert) ASSERT(ch>='0');
    return ch;
}
void dfs_max(char s[],int start,int k,int deep){
    if(debugassert) ASSERT(deep<20);
    if(find_max) return;//已经达到了理论最大值,直接返回
    if(k==0){
        //没有交换次数了,更新ans
        if(strcmp(ansmax,s)<0) strncpy(ansmax,s,len+1);
        return;
    }
    int diff=get_diff(s,smax);
    if(diff==len){
        //已经达到了理论最大值,将find_max设为true,结束搜素
        strncpy(ansmax,s,len+1);
        find_max=true;
        return;
    }
    //向下搜索swap那些剩余部分的最大值的位置
    int newstart=diff;
    if(debugassert) ASSERT(newstart<len-1);
    char ch=maxch(s,newstart);
    for(int i=newstart;i<len;i++){
        if(s[i]==ch){
            swap(s[newstart],s[i]);
            dfs_max(s,newstart,k-1,deep+1);
            if(find_max) return;
            swap(s[newstart],s[i]);
        }
    }
    return;
}
void dfs_min(char s[],int start,int k,int deep){
    //if(debugassert) ASSERT(deep<20);
    if(find_min) return;
    if(k==0){
         //没有交换次数了,更新ans
        if(strcmp(ansmin,s)>0) strncpy(ansmin,s,len+1);
        return;
    }
    int diff=get_diff(s,smin);
    if(diff==len){
        //已经达到了理论最小值,将find_min设为true,结束搜素
        strncpy(ansmin,s,len+1);
        find_min=true;
        return;
    }
    //向下搜索swap那些剩余部分的最大值的位置,处理一下前导0的情况
    int newstart=diff;
    if(debugassert) ASSERT(newstart<len-1);
    if(debugassert) ASSERT(deep==0||newstart>start);
    if(newstart==0){
        char ch=minch(s,newstart,EXCLUDE_ZERO);
        for(int i=newstart;i<len;i++){
            if(s[i]==ch){
                swap(s[newstart],s[i]);
                dfs_min(s,newstart,k-1,deep+1);
                if(find_min) return;
                swap(s[newstart],s[i]);
            }
        }
    }else{
        char ch=minch(s,newstart,INCLUDE_ZERO);
        for(int i=newstart;i<len;i++){
            if(s[i]==ch){
                swap(s[newstart],s[i]);
                dfs_min(s,newstart,k-1,deep+1);
                if(find_min) return;
                swap(s[newstart],s[i]);
            }
        }
    }
    return;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        char oris[MAXLEN],orismin[MAXLEN],orismax[MAXLEN];
        int k;
        scanf("%s%d",oris,&k);
        len=strlen(oris);
        get_max(oris),get_min(oris);
        strncpy(ansmin,smax,len+1),strncpy(ansmax,smin,len+1);
        find_max=find_min=false;
        strncpy(orismin,oris,len+1);
        dfs_min(orismin,0,k,0);
        strncpy(orismax,oris,len+1);
        dfs_max(orismax,0,k,0);
        printf("%s %s\n",ansmin,ansmax);
    }
    return 0;
}
