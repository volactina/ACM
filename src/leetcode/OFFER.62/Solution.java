import java.lang.reflect.*;
class Solution {
    public int lastRemaining(int n, int m) {
        ArrayList<Integer> a=new ArrayList<Integer>();
        for(int i=0;i<n;i++){
            a.add(i);
        }
        int nowpos=0;
        while(a.size()>1){
            nowpos=(nowpos+m-1)%(a.size());
            a.remove(nowpos);
        }
        return a.get(0);
    }
}