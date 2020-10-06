class Solution {
    public int surfaceArea(int[][] grid) {
        int cnt=0,rows=grid.length,cols=grid[0].length;
        //垂直方向
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]>0) cnt+=2;
            }
        }
        //x轴方向
        for(int i=0;i<rows;i++){
            int low=0,high=0;
            boolean up=false;
            for(int j=0;j<cols;j++){
                //这里可以化简代码
                if(up){
                    if(grid[i][j]>=high){
                        //持续上行
                        high=grid[i][j];
                    }else{
                        //上行拐点
                        cnt+=high-low;
                        up=false;
                        low=grid[i][j];
                    }
                }else{
                    if(grid[i][j]<=low){
                        //持续下行
                        low=grid[i][j];
                    }else{
                        //下行拐点
                        cnt+=high-low;
                        up=true;
                        high=grid[i][j];
                    }
                }
            }
            //最后一波
            if(up) cnt+=high-low;
            cnt+=high;
        }
        //y轴方向
        for(int j=0;j<cols;j++){
            int low=0,high=0;
            boolean up=false;
            for(int i=0;i<rows;i++){
                //这里可以化简代码
                if(up){
                    if(grid[i][j]>=high){
                        //持续上行
                        high=grid[i][j];
                    }else{
                        //上行拐点
                        cnt+=high-low;
                        up=false;
                        low=grid[i][j];
                    }
                }else{
                    if(grid[i][j]<=low){
                        //持续下行
                        low=grid[i][j];
                    }else{
                        //下行拐点
                        cnt+=high-low;
                        up=true;
                        high=grid[i][j];
                    }
                }
            }
            //最后一波
            if(up) cnt+=high-low;
            cnt+=high;
        }
        return cnt;
    }
}