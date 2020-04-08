import java.util.*;
public class Main{
	public static boolean isTwoBase(int x){
		if(x==0) return false;
		while(x>1){
			if(x%2==1) return false;
			x/=2;
		}
		return true;
	}
	public static void main(String args[]){
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		int[] a=new int[n];
		int maxnum=0;
		for(int i=0;i<n;i++){
			a[i]=in.nextInt();
			maxnum=Math.max(maxnum,a[i]);
		}
		boolean ans=true;
		for(int i=0;i<n;i++){
			if(maxnum%a[i]!=0){
				ans=false;
				break;
			}
			if(!isTwoBase(maxnum/a[i])){
				ans=false;
				break;
			}
		}
		System.out.println(ans?"YES":"NO");
	}
}