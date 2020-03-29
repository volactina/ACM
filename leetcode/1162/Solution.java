class Solution {
    private final boolean DEBUG=false;
    private final int[] dx={0,0,1,-1};
    private final int[] dy={1,-1,0,0};
    public int maxDistance(int[][] grid) {
        int rows=grid.length,cols=grid[0].length;
        Queue<Pair<Integer,Integer>> q=new LinkedList<Pair<Integer,Integer>>();
        boolean[][] visited=new boolean[rows][cols];
        int[][] mindis=new int[rows][cols];
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1){
                    Pair<Integer,Integer> p=new Pair<>(i,j);
                    mindis[i][j]=0;
                    q.offer(p);
                    visited[i][j]=true;
                }
            }
        }
        int ans=-1;
        while(q.peek()!=null){
            Pair<Integer,Integer> nowgrid=q.poll();
            int nowx=nowgrid.getKey(),nowy=nowgrid.getValue();
            for(int i=0;i<4;i++){
                int newx=nowx+dx[i];
                int newy=nowy+dy[i];
                if(!(newx>=0&&newx<rows&&newy>=0&&newy<cols&&!visited[newx][newy])){
                    continue;
                }
                Pair<Integer,Integer> newgrid=new Pair<>(newx,newy);
                mindis[newx][newy]=mindis[nowx][nowy]+1;
                q.offer(newgrid);
                visited[newx][newy]=true;
                ans=Math.max(ans,mindis[newx][newy]);
            }
        }
        return ans;
    }
}