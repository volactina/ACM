import java.util.*;
public class Main{
	public static void main(String args[]){
		Scanner in=new Scanner(System.in);
		String s=in.next();
		int[] cnt=new int[26];
		for(int i=0;i<s.length();i++){
			cnt[s.charAt(i)-'a']++;
		}
		int[] num=new int[10];
		/*0,2,4,6,8*/
		//0
		num[0]=cnt['z'-'a'];
		cnt['z'-'a']-=num[0];
		cnt['e'-'a']-=num[0];
		cnt['r'-'a']-=num[0];
		cnt['o'-'a']-=num[0];
		//2
		num[2]=cnt['w'-'a'];
		cnt['t'-'a']-=num[2];
		cnt['w'-'a']-=num[2];
		cnt['o'-'a']-=num[2];
		//4
		num[4]=cnt['u'-'a'];
		cnt['f'-'a']-=num[4];
		cnt['o'-'a']-=num[4];
		cnt['u'-'a']-=num[4];
		cnt['r'-'a']-=num[4];
		//6
		num[6]=cnt['x'-'a'];
		cnt['s'-'a']-=num[6];
		cnt['i'-'a']-=num[6];
		cnt['x'-'a']-=num[6];
		//8
		num[8]=cnt['g'-'a'];
		cnt['e'-'a']-=num[8];
		cnt['i'-'a']-=num[8];
		cnt['g'-'a']-=num[8];
		cnt['h'-'a']-=num[8];
		cnt['t'-'a']-=num[8];
		/*1,3,5,7*/
		//1
		num[1]=cnt['o'-'a'];
		cnt['o'-'a']-=num[1];
		cnt['n'-'a']-=num[1];
		cnt['e'-'a']-=num[1];
		//3
		num[3]=cnt['t'-'a'];
		cnt['t'-'a']-=num[3];
		cnt['h'-'a']-=num[3];
		cnt['r'-'a']-=num[3];
		cnt['e'-'a']-=2*num[3];
		//5
		num[5]=cnt['f'-'a'];
		cnt['f'-'a']-=num[5];
		cnt['i'-'a']-=num[5];
		cnt['v'-'a']-=num[5];
		cnt['e'-'a']-=num[5];
		//7
		num[7]=cnt['s'-'a'];
		cnt['s'-'a']-=num[7];
		cnt['e'-'a']-=2*num[7];
		cnt['v'-'a']-=num[7];
		cnt['n'-'a']-=num[7];
		/*9*/
		num[9]=cnt['i'-'a'];
		cnt['n'-'a']-=2*num[9];
		cnt['i'-'a']-=num[9];
		cnt['e'-'a']-=num[9];
		//output
		for(int i=0;i<10;i++){
			for(int j=0;j<num[i];j++){
				System.out.print(i);
			}
		}
		System.out.println();
	}
}