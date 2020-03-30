import java.util.*;
public class Main{
    static String[] sname;
    static String[] svalue;
    static boolean[] known;
    static Map mp;
    static final boolean DEBUG=false;
    public static boolean isKnown(String value){
        //判断值是否已知，读入必须来自svalue
        int pos1=value.indexOf("${");
        int pos2=value.indexOf("}",pos1);
        if(pos1!=-1&&pos2!=-1) return false;
        return true;
    }
    public static String firstUnknown(String value){
        //返回第一个未知量，如果已知返回空串
        if(isKnown(value)) return "";
        int pos1=value.indexOf("${");
        int pos2=value.indexOf("}",pos1);
        return value.substring(pos1+2,pos2);
    }
    public static String updateValue(String value,String oldv,String newv){
        //将value中的old部分替换为newv部分
        while(value.indexOf(oldv)!=-1){
            int sold=value.indexOf(oldv),lenold=oldv.length();
            value=value.substring(0,sold)+newv+value.substring(sold+lenold);
        }
        return value;
    }
    public static String findValue(String name){
        //尝试照寻某一个变量name的值value
        int id=(int)mp.get(name);
        if(known[id]){
            if(DEBUG) System.out.println("value of "+name+" is already known:"+svalue[id]);
            return svalue[id];
        } 
        if(DEBUG) System.out.println("looking for "+name+",current value:"+svalue[id]);
        while(!isKnown(svalue[id])){
            String findname=firstUnknown(svalue[id]);
            if(DEBUG) System.out.println("first unkown of "+name+" is "+findname);
            String findnamevalue=findValue(findname);
            if(DEBUG) System.out.println("we find out value of "+findname+" is "+findnamevalue);
            int findid=(int)mp.get(findname);
            known[findid]=true;
            svalue[findid]=findnamevalue;
            //更新
            String oldvalue="${"+findname+"}";
            if(DEBUG) System.out.println("we want to replace old:"+oldvalue+" to new:"+findnamevalue);
            svalue[id]=updateValue(svalue[id],oldvalue,findnamevalue);
            //svalue[id]=svalue[id].replaceAll(oldvalue,findnamevalue);
            if(DEBUG) System.out.println("Update "+name+" to value:"+svalue[id]);
        }
        known[id]=true;
        return svalue[id];
    }
    public static void main(String args[]){
        //初始化，读入数据，用一个map来给变量名标号
        Scanner in=new Scanner(System.in);
        int n=in.nextInt();
        mp=new HashMap();
        sname=new String[n];
        svalue=new String[n];
        known=new boolean[n];
        for(int i=0;i<n;i++){
            String s=in.next();
            sname[i]=s.substring(0,s.indexOf("="));
            svalue[i]=s.substring(s.indexOf("=")+1);
            known[i]=isKnown(svalue[i]);
            mp.put(sname[i],i);
        }
        System.out.println(findValue(sname[n-1]));
    }
}