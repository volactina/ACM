import java.util.*;
public class Main{
	public static void main(String args[]){
		Scanner in=new Scanner(System.in);
		int n=in.nextInt(),k=in.nextInt();
		int[] endt=new int[1000];
		endt[0]=n;
		while(k-->0){
			int t=in.nextInt(),m=in.nextInt();
			endt[t]=m;
		}
		for(int i=1;i<1000;i++){
			if(endt[i]==0) endt[i]=endt[i-1];
		}
		double now=0;
		int nowt=0;
		while(now<1){
			int leftt=endt[nowt]-nowt;
			double work=(1-now)/leftt;
			now+=work;
			nowt++;
			System.out.printf("%.2f\n",now);
		}
	}
}