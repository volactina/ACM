#include <bits/stdc++.h>
#define MAXROOM 510
#define MAXROAD 610

using namespace std;

int main()
{
    int roomnum,roadnum,from,to,score[MAXROOM],cost[MAXROOM][MAXROOM],spath[MAXROOM],mscore[MAXROOM];
    memset(cost,-1,sizeof(cost)),memset(mscore,0,sizeof(mscore));
    for (int i=0;i<MAXROOM;i++) spath[i]=INT_MAX;
    cin>>roomnum>>roadnum>>from>>to;
    for (int i=0;i<roomnum;i++) cin>>score[i];
    while(roadnum--){
        int x,y,z;
        cin>>x>>y>>z;
        cost[x][y]=cost[y][x]=z;
    }
    spath[from]=0,mscore[from]=score[from];
    queue<int> q;
    bool exist[MAXROOM];
    memset(exist,false,sizeof(exist));
    while(!q.empty()) q.pop();
    q.push(from);
    exist[from]=true;
    while(!q.empty()){
        int nowroom=q.front();
        q.pop();
        exist[nowroom]=false;
        for (int i=0;i<roomnum;i++){
            if (cost[nowroom][i]>=0&&((spath[nowroom]+cost[nowroom][i]<spath[i])||((spath[nowroom]+cost[nowroom][i]==spath[i])&&(mscore[nowroom]+score[i]>mscore[i])))){
                spath[i]=spath[nowroom]+cost[nowroom][i],mscore[i]=mscore[nowroom]+score[i];
                if (!exist[i]) q.push(i),exist[i]=true;
            }
        }
    }
    cout<<spath[to]<<" "<<mscore[to]<<endl;
    return 0;
}
