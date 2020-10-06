#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAXN 110

using namespace std;

int rednum,bluenum,tot,choose[MAXN],ans=0;
vector<int> match[MAXN];
bool exist[MAXN];
bool dfs(int x){
    exist[x]=true;
    if (x<=rednum){
        for (int i=0;i<(int)match[x].size();i++){
            if (match[x][i]>rednum&&!exist[match[x][i]]&&dfs(match[x][i])){
                ans++;
                choose[x]=match[x][i];
                choose[match[x][i]]=x;
                exist[x]=false;
                return true;
            }
        }
    }else{
        if (choose[x]==-1){
            exist[x]=false;
            return true;//找到增广路径
        }else{
            if (!exist[choose[x]]&&dfs(choose[x])){//蓝到红取反消除
                ans--;
                //choose[choose[x]]=-1;
                //choose[x]=-1;
                exist[x]=false;
                return true;
            }
        }
    }
    exist[x]=false;
    return false;
}

int main()
{

    memset(match,false,sizeof(match));
    memset(choose,-1,sizeof(choose));
    for (int i=1;i<=tot;i++){
        match[i].clear();
    }
    scanf("%d%d",&rednum,&tot);
    bluenum=tot-rednum;
    int tempx,tempy;
    while (scanf("%d%d",&tempx,&tempy)&&!(tempx==-1&&tempy==-1)){
        match[tempx].push_back(tempy);
        match[tempy].push_back(tempx);
    }
    for (int i=1;i<=rednum;i++){
        memset(exist,false,sizeof(exist));
        if (choose[i]==-1) dfs(i);
        if (ans==min(rednum,bluenum)) break;
        //printf("%d:%d\n",i,ans);
        //while(dfs(i));
    }
    if (ans==0) printf("No Solution!\n");else printf("%d\n",ans);
    return 0;
}
