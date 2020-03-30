import java.util.*;
public class Solution {
    /**
     * 
     * @param a int整型 
     * @param b int整型 
     * @return string字符串
     */
    public String tailOfPower (int a, int b) {
        // write code here
        int tmp=a%1000,ans=1;
        for(int i=0;i<b;i++){
            ans=(ans*tmp)%1000;
        }
        String s=String.valueOf(ans);
        if(s.length()==1) return "00"+s;
        if(s.length()==2) return "0"+s;
        return s;
    }
}