#include <bits/stdc++.h>

using namespace std;

struct sudo{
    char ori[16][20];
    struct node{
        int ch[4][4];
    }rot[4][4][4];
    void Rotate(const node x,node &y){
        for(int i=0;i<4;i++) for(int j=0;j<4;j++) y.ch[j][3-i]=x.ch[i][j];
        return;
    }
    int val(char ch){
        assert((ch>='0'&&ch<='9')||(ch>='A'&&ch<='F'));
        if(ch>='0'&&ch<='9') return ch-'0';
        return ch-'A'+10;
    }
    void build_sudo(){
        for(int i=0;i<16;i++) scanf("%s",ori[i]);
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                for(int m=0;m<4;m++){
                    for(int k=0;k<4;k++){
                        rot[i][j][0].ch[m][k]=val(ori[4*i+m][4*j+k]);
                    }
                }
                for(int m=1;m<4;m++) Rotate(rot[i][j][m-1],rot[i][j][m]);
            }
        }
        return;
    }
    int check_col[4][4][16],check_row[4][4][16],nowr[4][4];
    int Solve(){
        memset(check_col,0,sizeof(check_col));
        memset(check_row,0,sizeof(check_row));
        int ans=INT_MAX;
        dfs(0,0,0,ans);
        return ans;
    }
    void dfs(int nowrow,int nowcol,int nowcnt,int &ans){
        if(nowcnt>=ans) return;//最优化减枝
        if(nowrow==4){
            ans=min(ans,nowcnt);
            return;
        }
        for(int r=0;r<4;r++){
            bool correct=true;
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    int nownum=rot[nowrow][nowcol][r].ch[i][j];
                    if(check_row[nowrow][i][nownum]){
                        correct=false;
                        break;
                    }
                    if(check_col[nowcol][j][nownum]){
                        correct=false;
                        break;
                    }
                }
                if(!correct) break;
            }
            if(!correct) continue;//可行性减枝
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    int nownum=rot[nowrow][nowcol][r].ch[i][j];
                    check_row[nowrow][i][nownum]++;
                    check_col[nowcol][j][nownum]++;
                }
            }
            nowcnt+=r;
            if(nowcnt<ans){//最优化减枝
                if(nowcol==3) dfs(nowrow+1,0,nowcnt,ans);
                else dfs(nowrow,nowcol+1,nowcnt,ans);
            }
            nowcnt-=r;
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    int nownum=rot[nowrow][nowcol][r].ch[i][j];
                    check_row[nowrow][i][nownum]--;
                    check_col[nowcol][j][nownum]--;
                }
            }
        }
        return;
    }
}SUDO;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        SUDO.build_sudo();
        printf("%d\n",SUDO.Solve());
    }
    return 0;
}
