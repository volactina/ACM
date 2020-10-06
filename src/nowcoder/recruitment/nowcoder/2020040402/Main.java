import java.util.*;
public class Main{
	public static boolean Match(String target,String pattern){
		if(pattern.equals("*")) return true;
		int nextQ=pattern.indexOf("?");
		int nextStar=pattern.indexOf("*");
		if(nextQ==-1&&nextStar==-1){
			//no ? or *
			return target.equals(pattern);
		}
		if(nextStar==-1){
			//only ?
			if(target.length()!=pattern.length()) return false;
			String t1=target.substring(0,nextQ);
			String p1=pattern.substring(0,nextQ);
			String t2=target.substring(nextQ+1);
			String p2=pattern.substring(nextQ+1);
			return t1.equals(p1)&&t2.equals(p2);
		}
		//has *
		String p1=pattern.substring(0,nextStar);
		if(!Match(target.substring(0,nextStar),pattern.substring(0,nextStar))) return false;
		int anotherStar=pattern.indexOf("*",nextStar+1);
		if(anotherStar==-1){
			//only 1 *
			String p2=pattern.substring(nextStar+1);
			return target.length()>=p2.length()&&Match(target.substring(target.length()-p2.length()),p2);
		}else{
			//at least 2 *
			String p2=pattern.substring(nextStar+1,anotherStar);
			int index2=target.indexOf(p2);
			int newindex=index2+p2.length();
			while(index2!=-1){
				if(Match(target.substring(newindex),pattern.substring(anotherStar))) return true;
				index2=target.indexOf(p2,index2+1);
			}
			return false;
		}

		//Match(target.substring(0,nextStar),pattern(0,nextStar));
	}
	public static void main(String args[]){
		Scanner in=new Scanner(System.in);
		String pattern=in.next(),target=in.next();
		System.out.println(Match(target,pattern));
	}
}