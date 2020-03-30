import java.util.*;
public class Main{
    public static final boolean DEBUG=false;//是否输出调试信息
    public static void main(String args[]){
        /*
            总体思路：先去括号，再解决所有乘除，最后解决所有加减，
            要注意减号和负号的区别，我这里做的操作是将负号替换为"r"做一个区分
        */
        Scanner in=new Scanner(System.in);
        String s=in.next();
        //去括号
        while(s.contains("(")){
            if(DEBUG) System.out.println("正在去括号，原始表达式："+s);
            //找出第1个里层括号,即第1个“)”和此前的最后1个"("
            int rb=s.indexOf(")");
            int lb=s.substring(0,rb).lastIndexOf("(");
            String tmp=s.substring(lb+1,rb);
            String news=s.substring(0,lb)+Multi_Divide(tmp)+s.substring(rb+1);
            s=news;
            if(DEBUG) System.out.println("结束去括号，新表达式："+s);
        }
        s=Multi_Divide(s);//计算完算式中的全部乘除运算
        s=Plus_Minus(s);//计算完算式中的全部加减运算
        System.out.println(ToNum(s));
    }
    public static int ToNum(String s){
        /*
           输入：不可以有加减乘除括号，可以有负号
           输出：整数（处理负号'r'）
        */
        s=s.replaceAll("r","-");
        while(s.length()>1&&s.charAt(0)==s.charAt(1)&&s.charAt(0)=='-') s=s.substring(2);
        if(s.length()==0) return 0;
        return Integer.parseInt(s);
    }

    public static String simplify(String s){
        /*
           输入：含有加减的算式
           输出：不含连续减号的算式（化简算式，负负得正）
       */
        s=s.replaceAll("r","-");
        boolean flag=true;
        while(flag){
            flag=false;
            for(int i=0;i<s.length()-1;i++){
                if(s.charAt(i)==s.charAt(i+1)&&s.charAt(i)=='-'){
                    flag=true;
                    if(i==0) s=s.substring(i+2);
                    else s=s.substring(0,i)+"+"+s.substring(i+2);
                    break;
                }
            }
        }
        return s;
    }
    public static String Multi_Divide(String s){
        /*
            输入：表达式不能有括号
            输出：不含括号、乘除的表达式
        */
        while(s.contains("*")||s.contains("/")){
            if(DEBUG) System.out.println("*/*/开始乘除*/*/");
            if(DEBUG) System.out.println("初始表达式:"+s);
            int multi=s.indexOf("*"),divide=s.indexOf("/");
            int prepos=-1,nowpos,nextpos=s.length();
            int nextplus,nextdivide,nextminus,nextmulti;
            int preplus,predivide,preminus,premulti;
            boolean isMulti=false;
            //确定第1个乘除
            if((multi<divide&&multi!=-1)||divide==-1){
                isMulti=true;
                nowpos=multi;
            }else{
                nowpos=divide;
            }
            premulti=s.substring(0,nowpos).lastIndexOf("*");
            predivide=s.substring(0,nowpos).lastIndexOf("/");
            preplus=s.substring(0,nowpos).lastIndexOf("+");
            preminus=s.substring(0,nowpos).lastIndexOf("-");
            nextmulti=s.indexOf("*",nowpos+1);
            nextdivide=s.indexOf("/",nowpos+1);
            nextplus=s.indexOf("+",nowpos+1);
            nextminus=s.indexOf("-",nowpos+1);
            if(nextmulti<0) nextmulti=s.length();
            if(nextdivide<0) nextdivide=s.length();
            if(nextplus<0) nextplus=s.length();
            if(nextminus<0) nextminus=s.length();

            //找到子表达式的范围（即只包含一个运算符的表达式）
            nextpos=Math.min(Math.min(nextmulti,nextdivide),Math.min(nextplus,nextminus));
            prepos=Math.max(Math.max(premulti,predivide),Math.max(preplus,preminus));
            if(DEBUG) System.out.println("rawnum1:"+s.substring(prepos+1,nowpos));
            if(DEBUG) System.out.println("rawnum2:"+s.substring(nowpos+1,nextpos));
            int num1=ToNum(Plus_Minus(s.substring(prepos+1,nowpos)));
            int num2=ToNum(Plus_Minus(s.substring(nowpos+1,nextpos)));
            int tmp;

            //计算最简表达式的值
            if(isMulti){
                tmp=num1*num2;
            }else{
                tmp=num1/num2;
            }
            if(DEBUG) System.out.println("tmp:"+tmp);
            String newnum=String.valueOf(tmp).replaceAll("-","r");
            String news=s.substring(0,prepos+1)+newnum+s.substring(nextpos);
            s=news;
            if(DEBUG) System.out.println("*/*/结束乘除*/*/,返回："+s);
        }
        //以防万一有”+“”-“
        s=Plus_Minus(s);
        return s;
    }
    public static String Plus_Minus(String s){
         /*
            输入：表达式不能有括号、乘除号
            输出：不含加减号的表达式
        */

        if(DEBUG) System.out.println("+-+-开始加减-+-+");
        if(DEBUG) System.out.println("初始表达式:"+s);
        //区分减号和符号
        s=s.replaceAll("r","-");
        s=simplify(s);
        if(DEBUG) System.out.println("替换后表达式:"+s);
        if(DEBUG) System.out.println("s:"+s);
        //只能有+或-操作,区分负号和减号
        while(s.substring(1).contains("+")||s.substring(1).contains("-")){
            //定位到第1个+或-的位置
            int plus=s.indexOf("+",1),minus=s.indexOf("-",1);
            boolean isPlus=false;
            int nowpos,nextplus,nextminus,nextpos=s.length();
            //定位到第2个+或-的位置
            if((plus<minus&&plus!=-1)||minus==-1){
                isPlus=true;
                nowpos=plus;
            }else{
                nowpos=minus;
            }
            nextplus=s.indexOf("+",nowpos+1);
            nextminus=s.indexOf("-",nowpos+1);
            //确定下一个符号位置
            if(nextplus<0) nextplus=s.length();
            if(nextminus<0) nextminus=s.length();
            nextpos=Math.min(nextplus,nextminus);
            if(DEBUG) System.out.println(nowpos+","+nextpos);
            if(DEBUG) System.out.println("rawnum1="+s.substring(0,nowpos));
            if(DEBUG) System.out.println("rawnum2="+s.substring(nowpos+1,nextpos));
            int num1=ToNum(s.substring(0,nowpos));
            int num2=ToNum(s.substring(nowpos+1,nextpos));
            if(DEBUG) System.out.println("num1="+num1);
            if(DEBUG) System.out.println("num2="+num2);
            int tmp;

            //计算最简表达式的值
            if(isPlus){
                tmp=num1+num2;
            }else{
                tmp=num1-num2;
            }
            String news=String.valueOf(tmp);
            news+=s.substring(nextpos);
            s=news;
            if(DEBUG) System.out.println("s:"+s);
        }
        //区分减号和负号
        s=String.valueOf(ToNum(s));
        if(s.charAt(0)=='-') s="r"+s.substring(1);
        if(DEBUG) System.out.println("+-+-结束加减-+-+,返回："+s);
        return s;
    }
}