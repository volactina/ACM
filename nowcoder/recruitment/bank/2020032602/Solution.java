import java.util.*;


public class Solution {
    private static final boolean DEBUG=true;
	//三万四千八百四十三亿九千七百六十八万八千七百三十五
	//三万四千八百四十三亿九千七百六十八万八千七百零三
	//三万四千八百零四亿九千七百六十八万八千七百零三
	//三万四千八百零四亿九千七百六十八万八千七百三
    public static String convert (String number) {
		if(number.length()>=2&&number.charAt(number.length()-2)=='百'){
			number=number+"十";
		}
		if(DEBUG) System.out.println("-------------"+number+"----------------");
		if(number.length()==2&&number.charAt(0)=='零'){
			number=number.substring(1);
		}
		if(number.length()==1){
			switch(number.charAt(0)){
				case '零':return "0";
				case '一':return "1";
				case '二':return "2";
				case '三':return "3";
				case '四':return "4";
				case '五':return "5";
				case '六':return "6";
				case '七':return "7";
				case '八':return "8";
				case '九':return "9";
			}
		}
        String[] ch={"","亿","万","千","百","十"};
		/*
		for(int i=0;i<6;i++){
			System.out.println(ch[i]);
		}*/
        int[] endindex=new int[6];
        int[] startindex=new int[6];
        int lastendindex=-1;
        endindex[0]=-1;
        for(int i=1;i<=5;i++){
			//System.out.println("-----"+i+"-------");
			//System.out.println("lastendindex="+lastendindex);
            if(endindex[i-1]==-1) startindex[i]=lastendindex+1;
            else startindex[i]=endindex[i-1]+1;
            endindex[i]=number.indexOf(ch[i],startindex[i]);
            if(endindex[i]>=0) lastendindex=endindex[i];
			//System.out.println("number="+number+"ch[i]="+ch[i]+","+number.indexOf(ch[i],startindex[i]));
			//System.out.println("startindex="+startindex[i]+",lastendindex="+lastendindex);
        }
		/*
        if(DEBUG){
            for(int i=1;i<=5;i++){
                System.out.println(startindex[i]+","+endindex[i]);
            }
        }*/
		String ans="";
		for(int i=1;i<=5;i++){
            String part="";
            if(endindex[i]>=0){
                part=convert(number.substring(startindex[i],endindex[i]));
            }else{
                if(i>=3) part="0";
            }
            if(i==2){
                while(part.length()<4){
                    part="0"+part;
                }
            }
            ans+=part;
        }
		if(lastendindex<number.length()-1) ans+=convert(number.substring(lastendindex+1));
		while(ans.length()>1&&ans.charAt(0)=='0') ans=ans.substring(1);
		if(DEBUG) System.out.println(ans);
		return ans;
    }
	public static void main(String args[]){
		Scanner in=new Scanner(System.in);
		String number=in.next();
		System.out.println(convert(number));
	}
}