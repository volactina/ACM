import java.util.*;
public class Main{
	public static void main(String args[]){
    	Scanner in=new Scanner(System.in);
        long a=in.nextLong(),b=in.nextLong(),s=in.nextLong();
        long dis=Math.abs(a)+Math.abs(b);//曼哈顿距离
        if(s>=dis&&(s%2==dis%2)) System.out.println("Yes");
        else System.out.println("No");
    }
}