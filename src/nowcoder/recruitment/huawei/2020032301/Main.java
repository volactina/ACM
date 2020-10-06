import java.util.*;
public class Main{
	private static final boolean DEBUG=false;
	static int k,n;
	//static int[] q;
	static boolean[] used;
	static HashSet<String> exist;
	static void search(int depth,int sum,String q){
		if(DEBUG){
			System.out.println("depth="+depth);
			System.out.println("sum="+sum);
			System.out.println("q="+q);
			for(int i=0;i<depth;i++){
				System.out.print(i+" ");
			}
			System.out.println();
		}
		if(sum>n) return;
		if(depth==k){
			if(sum==n){
				//去重
				if(DEBUG) System.out.println("fit");
				if(!exist.contains(q)){
					System.out.println(q);
					exist.add(q);
				}
				
			}
			return;
		}
		int startnum=1;
		if(q.length()>0) startnum=Integer.parseInt(q.substring(q.length()-1))+1;
		if(DEBUG) System.out.println("startnum="+startnum);
		for(int i=startnum;i<10;i++){
				if(!used[i]){
					used[i]=true;
					//q[depth]=i;
					//exist.add(q+i);
					search(depth+1,sum+i,q+i);
					used[i]=false;
				}
			}
		return;
	}
	public static void main(String args[]){
		if(DEBUG) System.out.println("hello");
		Scanner in=new Scanner(System.in);
		k=in.nextInt();n=in.nextInt();
		//q=new int[k];
		used=new boolean[10];//初始化false
		exist=new HashSet<String>();
		search(0,0,"");
	}
}