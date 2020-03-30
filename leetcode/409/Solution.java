class Solution {
    public int longestPalindrome(String s) {
        HashMap cnt=new HashMap();
        for(int i=0;i<26;i++){
            cnt.put('a'+i,0);
            cnt.put('A'+i,0);
        }
        for(int i=0;i<s.length();i++){
            cnt.put((int)s.charAt(i),(int)cnt.get((int)s.charAt(i))+1);
        }
        int ans=0;
        boolean hasodd=false;
        for(int i=0;i<26;i++){
            ans+=(int)cnt.get('a'+i)/2*2;
            ans+=(int)cnt.get('A'+i)/2*2;
            if((int)cnt.get('a'+i)%2==1||(int)cnt.get('A'+i)%2==1){
                hasodd=true;
            }
        }
        if(hasodd) ans++;
        return ans;
    }
}