class Solution {
    public boolean canSpell(String word,String chars){
        for(int i=0;i<word.length();i++){
            int index=chars.indexOf(word.charAt(i));
            if(index==-1) return false;
            chars=chars.substring(0,index)+chars.substring(index+1);
        }
        return true;
    }
    public int countCharacters(String[] words, String chars) {
        int ans=0;
        for(int i=0;i<words.length;i++){
            if(canSpell(words[i],chars)){
                ans+=words[i].length();
            }
        }
        return ans;
    }
}