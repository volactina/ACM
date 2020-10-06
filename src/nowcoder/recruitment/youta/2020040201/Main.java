import java.util.*;
public class Main{
	private static final boolean DEBUG=false;
	public static void main(String args[]){
		Scanner in=new Scanner(System.in);
		String n=in.next(),k=in.next();
		int nlen=n.length(),klen=k.length();
		int[] ans=new int[nlen+klen+5];
		for(int i=0;i<klen;i++){
			for(int j=0;j<nlen;j++){
				if(DEBUG){
					System.out.println("i="+i+",j="+j);
					System.out.println(k.charAt(i)+"--"+n.charAt(j));
				}
				int num=Integer.parseInt(""+k.charAt(i))*Integer.parseInt(""+n.charAt(j));
				int index=(klen-i-1)+(nlen-j-1);
				ans[index]+=num;
			}
		}
		for(int i=0;i<ans.length-1;i++){
			ans[i+1]+=ans[i]/10;
			ans[i]%=10;
		}
		boolean first=true;
		for(int i=ans.length-1;i>=0;i--){
			if(DEBUG) System.out.println("i="+i+",first="+first);
			if(first){
				if(ans[i]!=0){
					if(DEBUG) System.out.println("start change first,fisrt="+first);
					first=false;
					if(DEBUG) System.out.println("finish change first,fisrt="+first);
					System.out.print(ans[i]);
					if(DEBUG){
						System.out.println("first="+i);
					}
				}
			}else{
				if(DEBUG) System.out.println("i="+i);
				System.out.print(ans[i]);
			}
		}
		if(first) System.out.print("0");
		System.out.println();
	}
}