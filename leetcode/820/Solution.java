class Solution {
    public boolean isSuffix(String a,String b){
        /*return whether b is a suffix of a*/
        int index=a.lastIndexOf(b);
        if(index==-1) return false;
        if(index+b.length()==a.length()) return true;
        return false;
    }
    public int minimumLengthEncoding(String[] words) {
        ArrayList<String> q=new ArrayList<String>(0);
        for(int i=0;i<words.length;i++){
            boolean hasPos=false;
            for(int j=0;j<q.size();j++){
                if(isSuffix(words[i],q.get(j))){
                    hasPos=true;
                    q.set(j,words[i]);
                }else if(isSuffix(q.get(j),words[i])){
                    hasPos=true;
                }
            }
            if(!hasPos) q.add(words[i]);
        }
        int ans=0;
        for(int i=0;i<q.size();i++){
            ans+=q.get(i).length();
        } 
        ans+=q.size();
        return ans;
    }
}