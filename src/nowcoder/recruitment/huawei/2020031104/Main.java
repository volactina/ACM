import java.util.*;
public class Main{
    public static void main(String args[]){
        Scanner in=new Scanner(System.in);
        int x=in.nextInt();
        int cnt=0;
        while(x!=0){
            if(x%2==1) cnt++;
            x/=2;
        }
        System.out.println(cnt);
    }
}