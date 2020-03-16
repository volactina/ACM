class Solution {
    public String compressString(String S) {
        if(S.length()==0) return S;
        String news="";
        char nowchar=S.charAt(0);
        int cnt=1;
        for(int i=1;i<S.length();i++){
            char c=S.charAt(i);
            if(nowchar==c) cnt++;
            else{
                news+=String.valueOf(nowchar)+cnt;
                nowchar=c;
                cnt=1;
            }
        }
        if(cnt>0) news+=String.valueOf(nowchar)+cnt;
        if(news.length()<S.length()) return news;
        return S;
    }
}