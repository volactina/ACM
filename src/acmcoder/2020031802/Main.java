import java.util.*;
import java.lang.*;
public class Main{
	public final static boolean DEBUG=false;
	public static void main(String args[]){
		Scanner in=new Scanner(System.in);
		String s=in.next();
		StringBuffer tmp=new StringBuffer();
		int tmplen=0;
		for(int i=0;i<s.length();i++){
			if(DEBUG) System.out.println(i+" begin:"+tmp);
			if(tmplen>0&&tmp.charAt(tmplen-1)=='('&&s.charAt(i)==')'){
				tmp.deleteCharAt(tmplen-1);
				tmplen--;
			}else if(tmplen>0&&tmp.charAt(tmplen-1)=='['&&s.charAt(i)==']'){
				tmp.deleteCharAt(tmplen-1);
				tmplen--;
			}else if(tmplen>0&&tmp.charAt(tmplen-1)=='{'&&s.charAt(i)=='}'){
				tmp.deleteCharAt(tmplen-1);
				tmplen--;
			}else{
				tmp.append(s.charAt(i));
				tmplen++;
			}
			if(DEBUG) System.out.println(i+" end:"+tmp);
		}
		if(tmplen==0) System.out.println("true");else System.out.println("false");
	}
}