import java.util.*;
public class Main{
	public static void main(String args[]){
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		int ans=0,now=0;
		for(int i=0;i<n;i++){
			int a=in.nextInt(),b=in.nextInt();
			now+=-a+b;
			ans=Math.max(ans,now);
		}
		System.out.println(ans);
	}
}