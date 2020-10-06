class Solution {
    private final boolean DEBUG=false;
    private final int[] dx={0,0,-1,1};
    private final int[] dy={-1,1,0,0};
    public int numIslands(char[][] grid) {
        if(grid.length==0) return 0;
        int rownum=grid.length,colnum=grid[0].length;
        boolean[][] visited=new boolean[rownum][colnum];
        Queue<Pair<Integer,Integer>> q=new LinkedList<>();
        int cnt=0;
        for(int i=0;i<rownum;i++){
            for(int j=0;j<colnum;j++){
                if(DEBUG){
                    System.out.println("i="+i+",j="+j+",v="+visited[i][j]+",g="+grid[i][j]);
                    System.out.println(!visited[i][j]);
                    System.out.println(grid[i][j]==1);
                    System.out.println(!visited[i][j]&&grid[i][j]==1);
                }
                if(!visited[i][j]&&grid[i][j]=='1'){
                    cnt++;
                    //System.out.println("cnt="+cnt);
                    Pair<Integer,Integer> p=new Pair<>(i,j);
                    visited[i][j]=true;
                    q.offer(p);
                    while(q.size()>0){
                        Pair<Integer,Integer> nowp=q.poll();
                        for(int k=0;k<4;k++){
                            int newx=nowp.getKey()+dx[k],newy=nowp.getValue()+dy[k];
                            if(newx>=0&&newx<rownum&&newy>=0&&newy<colnum){
                                if(!visited[newx][newy]){
                                    visited[newx][newy]=true;
                                    if(grid[newx][newy]=='1'){
                                        q.offer(new Pair<Integer,Integer>(newx,newy));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
}