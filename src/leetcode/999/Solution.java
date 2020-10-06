class Solution {
    public static final int dirx[]={0,0,1,-1};
    public static final int diry[]={1,-1,0,0};
    public static final int rows=8,cols=8;
    public int numRookCaptures(char[][] board) {
        int Rx=-1,Ry=-1;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]=='R'){
                    Rx=i;Ry=j;
                    break;
                }
            }
            if(Rx>0) break;
        }
        int ans=0;
        for(int i=0;i<4;i++){
            int nowx=Rx,nowy=Ry;
            nowx+=dirx[i];nowy+=diry[i];
            while(nowx>=0&&nowx<rows&&nowy>=0&&nowy<cols){
                if(board[nowx][nowy]=='B'){
                    break;
                }
                if(board[nowx][nowy]=='p'){
                    ans++;
                    break;
                }
                nowx+=dirx[i];nowy+=diry[i];
            }
        }
        return ans;
    }
}