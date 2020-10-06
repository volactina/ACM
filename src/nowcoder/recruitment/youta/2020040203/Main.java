import java.util.*;
public class Main{
	private static int m,n;
	private static int[][] t;
	private static int[][] tmin;
	private final static int[] dirx={0,0,-1,1};
	private final static int[] diry={-1,1,0,0};
	private static void dfs(int x,int y,int nowt){
		if(t[x][y]==0){
			return;
		}
		nowt+=t[x][y];
		if(tmin[x][y]!=-1&&nowt>=tmin[x][y]) return;
		tmin[x][y]=nowt;
		if(x==m-1&&y==n-1) return;
		for(int i=0;i<4;i++){
			int newx=x+dirx[i],newy=y+diry[i];
			if(newx>=0&&newx<m&&newy>=0&&newy<n){
				dfs(newx,newy,nowt);
			}
		}
		return;
	}
	public static void main(String args[]){
		Scanner in=new Scanner(System.in);
		m=in.nextInt();n=in.nextInt();
		t=new int[m][n];
		tmin=new int[m][n];
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				t[i][j]=in.nextInt();
				tmin[i][j]=-1;
			}
		}
		dfs(0,1,0);
		dfs(1,0,0);
		System.out.println(tmin[m-1][n-1]);
	}
}