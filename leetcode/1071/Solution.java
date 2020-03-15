class Solution {
    public boolean isDivisor(String str,String sdiv){
        int lenstr=str.length(),lensdiv=sdiv.length();
        if(lenstr%lensdiv!=0) return false;
        int num=lenstr/lensdiv;
        for(int i=0;i<num;i++){
            if(str.indexOf(sdiv,i*lensdiv)==-1) return false;
        }
        return true;
    }
    public String gcdOfStrings(String str1, String str2) {
        //枚举
        String str="";
        String ans="";
        for(int i=0;i<Math.min(str1.length(),str2.length());i++){
            str+=str1.substring(i,i+1);
            if(isDivisor(str1,str)&&isDivisor(str2,str)){
                ans=str;
            }
        }
        return ans;
    }
}