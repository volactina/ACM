import java.util.*;
public class Main{
	private static final boolean DEBUG=false;
	public static void main(String args[]){
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		while(n-->0){
			String target=in.next();
			target+=target;
			int m=in.nextInt();
			String[] s=new String[m];
			for(int i=0;i<m;i++){
				s[i]=in.next();
			}
			int start=0,end=0;
			boolean first=true;
			while(end-start<target.length()/2){
				boolean flag=false;
				for(int i=0;i<m;i++){
					int index;
					if(first){
						index=target.indexOf(s[i]);
						if(DEBUG){
							System.out.println("start="+start+"s[i]="+s[i]+",index="+index);
						}
						if(index!=-1){
							first=false;
							flag=true;
							start=index;
							end=start+s[i].length();
							if(DEBUG){
								System.out.println("first!start="+start+",end="+end);
							}
						}
					}else{
						index=target.indexOf(s[i],end);
						if(DEBUG){
							System.out.println("start="+start+"end="+end+"s[i]="+s[i]+",index="+index);
						}
						if(index==end){
							if(DEBUG){
								System.out.println("fit:"+s[i]+",end="+end);
							}
							flag=true;
							end+=s[i].length();
							break;
						}
					}
				}
				if(!flag) break;
			}
			if(end-start<target.length()/2) System.out.print("false");
			else System.out.print("true");
			if(n==0) System.out.println();else System.out.print(" ");
		}
	}
}