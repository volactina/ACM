import java.util.*;
public class Main{
	public static void main(String args[]){
		Scanner in=new Scanner(System.in);
		String s1=in.next(),s2=in.next();
		int cnt=0;
		for(int i=0;i<s1.length();i++){
			if (Character.isLetter(s1.charAt(i))||Character.isDigit(s1.charAt(i))){
				if(s2.charAt(i)=='1') cnt++;
			}else{
				if(s2.charAt(i)=='0') cnt++;
			}
		}
		double ans=cnt*100.0/s2.length();
		System.out.printf("%.2f%%",ans);
	}
}