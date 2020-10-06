import java.util.*;
public class Main{
    public static void main(String args[]){
        Scanner in=new Scanner(System.in);
        String line=in.next();
        String[] s=line.split("#");
        boolean ans=true;
        for(int i=0;i<s[1].length();i++){
            if(s[0].indexOf(s[1].charAt(i))==-1){
                ans=false;
                break;
            }
        }
        System.out.println(ans);
	}
}