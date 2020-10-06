class Solution {
    public int gcd(int x,int y){
        return x%y==0?y:gcd(y,x%y);
    }
    public boolean hasGroupsSizeX(int[] deck) {
        Arrays.sort(deck);
        int s=0,t=0,nownum=deck[0],nowgcd=-1;
        boolean second=false;
        for(int i=1;i<deck.length;i++){
            if(deck[i]==nownum){
                t++;
            }else{
                int cnt=t-s+1;
                if(second){
                    nowgcd=gcd(nowgcd,cnt);
                }else{
                    second=true;
                    nowgcd=cnt;
                }
                s=t=i;
                if(nowgcd==1) return false;
            }
            nownum=deck[i];
        }
        if(!second) return t-s+1>1; 
        nowgcd=gcd(nowgcd,t-s+1);
        if(nowgcd==1) return false;
        return true;
    }
}