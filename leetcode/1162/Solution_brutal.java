class Solution_brutal {
    private final boolean DEBUG=false;
    public int maxDistance(int[][] grid) {
        int rows=grid.length,cols=grid[0].length;
        if(DEBUG){
            System.out.println("rows="+rows+",cols="+cols);
        }
        int[][] mindis=new int[rows][cols];
        //initialization
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                mindis[i][j]=(grid[i][j]==1)?-1:rows+cols;
            }
        }
        //calculate
        for(int i1=0;i1<rows;i1++){
            for(int j1=0;j1<cols;j1++){
                for(int i2=i1;i2<rows;i2++){
                    for(int j2=0;j2<cols;j2++){
                        if(DEBUG){
                            System.out.println("("+i1+","+j1+")("+i2+","+j2+")");
                        }
                        if(grid[i1][j1]+grid[i2][j2]!=1) continue;
                        int dis=Math.abs(i1-i2)+Math.abs(j1-j2);
                        if(DEBUG){
                            System.out.println("("+i1+","+j1+")("+i2+","+j2+")="+dis);
                        }
                        mindis[i1][j1]=Math.min(mindis[i1][j1],dis);
                        mindis[i2][j2]=Math.min(mindis[i2][j2],dis);
                    }
                }
            }
        }
        if(DEBUG){
            for(int i=0;i<rows;i++){
                for(int j=0;j<cols;j++){
                    System.out.print(mindis[i][j]+",");
                }
                System.out.println();
            }
        }
        //output
        //int maxnum=-1;
        int ans=-1;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                ans=Math.max(ans,mindis[i][j]);
            }
        }
        return ans==rows+cols?-1:ans;
    }
}