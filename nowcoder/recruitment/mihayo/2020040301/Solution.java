import java.util.*;
public class Solution {
    public boolean Match (String s, String p) {
        //""
		if(s.length()==0&&p.length()>1&&p.charAt(1)=='*') return true;
		if(p.length()==0&&s.length()==0) return true;
		if(p.length()==0&&s.length()!=0) return false;
		//.*
		int index1=p.indexOf(".*");
		if(index1!=-1){
			if(p.length()==2) return true;
			int nextIndex1=p.indexOf(".*",index1+2);
			if(nextIndex1==-1){
				if(s.lastIndexOf(p.substring(index1+2))+p.substring(index1+2).length()==s.length()) return true;
				return false;
			}else{
				int index12=s.indexOf(p.substring(index1+2,nextIndex1));
				if(index12==-1) return false;
				return Match(s.substring(index12+p.substring(index1+2,nextIndex1).length()),p.substring(nextIndex1+2));
			}
		}
		//()*
		int index2=p.indexOf(")*");
		
		
		
		
		
		
		
		int nextDot=p.indexOf("."),nextLeftBracket=p.indexOf("("),nextStar=p.indexOf("*");
		int nextPos=Math.max(nextDot,Math.max(nextLeftBracket,nextStar));
		if(nextDot!=-1) nextPos=Math.min(nextPos,nextDot);
		if(nextLeftBracket!=-1) nextPos=Math.min(nextPos,nextLeftBracket);
		if(nextStar!=-1) nextPos=Math.min(nextPos,nextStar);
		//()
		if(nextPos!=-1&&nextPos==nextLeftBracket){
			if(s.indexOf(p.substring(0,nextLeftBracket))!=0) return false;
			int nextRightBracket,cnt=1;
			for(nextRightBracket=nextLeftBracket+1;;nextRightBracket++){
				if(p.charAt(nextRightBracket)=='('){
					cnt++;
				}else if(p.charAt(nextRightBracket)==')'){
					cnt--;
					if(cnt==0) break;
				}
			}
			if(p.length()-1==nextRightBracket||p.charAt(nextRightBracket+1)!='*'){
				String newp=p.substring(nextLeftBracket+1,nextRightBracket)+p.substring(nextRightBracket+1);
				return Match(s.substring(nextLeftBracket+1),newp);
			}
			//if(s.indexOf(p.substring(nextLeftBracket+1,nextRightBracket))==)
		}
		//.
		if(nextPos!=-1&&nextPos==nextDot){
			if(s.indexOf(p.substring(0,nextDot))!=0) return false;
			if(p.length()==nextDot+1||p.charAt(nextDot+1)!='*'){
				return Match(s.substring(nextDot+1),p.substring(nextDot+1));
			}
			
		}
		//_*
		if(nextPos!=-1&&nextPos==nextStar){
			if(s.indexOf(p.substring(0,nextStar-1))!=0) return false;
			if(s.length()-1<nextStar-1) return false;
			if(s.charAt(nextStar-1)==p.charAt(nextStar-1)){
				if(s.length()==nextStar){
					if(nextStar==p.length()) return true;
					return false;
				}
				return Match(s.substring(nextStar),p.substring(nextStar-1));
			}else{
				return Match(s,p.substring(nextStar+1));
			}
		}
		return s.equals(p);
    }
}