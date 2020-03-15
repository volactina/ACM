class Solution {
    int[][] g;
    boolean[][] visited;
    int maxarea,nowarea;
    final int[] dx={-1,1,0,0};
    final int[] dy={0,0,-1,1};
    public void dfs(int x,int y,int depth){
        nowarea++;
        visited[x][y]=true;
        for(int i=0;i<4;i++){
            int newx=x+dx[i],newy=y+dy[i];
            if(g[newx][newy]==1&&!visited[newx][newy]){
                dfs(newx,newy,depth+1);
            }
        }
        return;
    }
    public int maxAreaOfIsland(int[][] grid) {
        //添加隔离层
        int rows=grid.length+2,cols=grid[0].length+2;
        g=new int[rows][cols];

        for(int i=1;i<rows-1;i++){
            for(int j=1;j<cols-1;j++){
                g[i][j]=grid[i-1][j-1];
            }
        }
        visited=new boolean[rows][cols];
        maxarea=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(g[i][j]==1&&!visited[i][j]){
                    nowarea=0;
                    dfs(i,j,1);
                    maxarea=Math.max(nowarea,maxarea);
                }
            }
        }
        return maxarea;
    }
}