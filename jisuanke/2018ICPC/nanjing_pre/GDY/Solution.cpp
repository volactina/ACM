#include <bits/stdc++.h>
#define MAXN 210

using namespace std;

const int f1[]={0,12,13,1,2,3,4,5,6,7,8,9,10,11},f2[]={0,3,4,5,6,7,8,9,10,11,12,13,1,2};

int main(){
    int t;
    scanf("%d",&t);
    for(int casenum=1;casenum<=t;casenum++){
        int playernum,cardsnum,have[MAXN][14];
        queue<int> cards;
        while(!cards.empty()) cards.pop();
        memset(have,0,sizeof(have));
        scanf("%d%d",&playernum,&cardsnum);
        for(int i=0;i<cardsnum;i++){
            int tmp;
            scanf("%d",&tmp);
            cards.push(f1[tmp]);
        }
        for(int i=1;i<=playernum;i++){
            if(cards.empty()) break;
            for(int j=1;j<=5;j++){
                if(cards.empty()) break;
                have[i][0]++;
                have[i][cards.front()]++;
                cards.pop();
            }
        }
        int nowplayer=1,nowcard=-1;
        bool finish=false;
        while(true){
            if(nowcard==-1){
                for(int i=1;i<=13;i++){
                    if(have[nowplayer][i]){
                        nowcard=i;
                        have[nowplayer][i]--;
                        have[nowplayer][0]--;
                        if(have[nowplayer][0]==0){
                            finish=true;
                            break;
                        }
                        if(nowcard==13){
                            nowcard=-1;
                            for(int j=0;j<playernum;j++){
                                if(cards.empty()) break;
                                int tmp=(nowplayer+j-1)%playernum+1;
                                have[tmp][cards.front()]++;
                                have[tmp][0]++;
                                cards.pop();
                            }
                        }
                        break;
                    }
                }
                if(finish) break;
            }else{
                int nextplayer;
                bool found=false;
                for(nextplayer=nowplayer%playernum+1;nextplayer!=nowplayer;nextplayer=(nextplayer%playernum)+1){
                    if(have[nextplayer][nowcard+1]||have[nextplayer][13]){
                        found=true;
                        if(have[nextplayer][nowcard+1]){
                            have[nextplayer][nowcard+1]--;
                            nowcard=nowcard+1;
                        }else{
                            have[nextplayer][13]--;
                            nowcard=13;
                        }
                        have[nextplayer][0]--;
                        if(have[nextplayer][0]==0) finish=true;
                        nowplayer=nextplayer;
                        if(nowcard==13){
                            nowcard=-1;
                            for(int j=0;j<playernum;j++){
                                if(cards.empty()) break;
                                int tmp=(nowplayer+j-1)%playernum+1;
                                have[tmp][cards.front()]++;
                                have[tmp][0]++;
                                cards.pop();
                            }
                        }
                        break;
                    }
                }
                if(finish) break;
                if(!found){
                    nowcard=-1;
                    for(int j=0;j<playernum;j++){
                        if(cards.empty()) break;
                        int tmp=(nowplayer+j-1)%playernum+1;
                        have[tmp][cards.front()]++;
                        have[tmp][0]++;
                        cards.pop();
                    }
                }
            }
        }
        printf("Case #%d:\n",casenum);
        for(int i=1;i<=playernum;i++){
            if(have[i][0]==0) printf("Winner\n");
            else{
                int ans=0;
                for(int j=1;j<=13;j++) ans+=have[i][j]*f2[j];
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
