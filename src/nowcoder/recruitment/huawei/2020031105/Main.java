import java.util.*;
public class Main{
    public static void main(String args[]){
        Scanner in=new Scanner(System.in);
        String s=in.next();
        String rs="";
        for(int i=s.length()-1;i>=0;i--){
            rs+=s.charAt(i);
        }
        System.out.println(rs);
    }
}