import java.util.*;
public class Solution{
	private static final boolean DEBUG=true;
	public static void main(String args[]){
		Scanner in=new Scanner(System.in);
		String s=in.next();
		if(s.length()==0){
			System.out.println("0");
			return;
		}
		int ans=1,nowstart=0,nowend=0;
		HashSet<Character> exist=new HashSet<Character>();
		exist.add(s.charAt(0));
		for(int i=1;i<s.length();i++){
			if(DEBUG) System.out.println("nowchar:"+s.charAt(i)+" "+exist.contains(s.charAt(i)));
			if(!exist.contains(s.charAt(i))){
				nowend++;
				ans=Math.max(ans,nowend-nowstart+1);
				exist.add(s.charAt(i));
			}else{
				nowstart=nowend=i;
				exist.clear();
				exist.add(s.charAt(i));
				//if(DEBUG) System.out.println(exist.contains('b'));
			}
		}
		System.out.println(ans);
	}
}