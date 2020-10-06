class Solution {
    final boolean DEBUG=false;
    public int minIncrementForUnique(int[] A) {
        if(A.length==0) return 0;
        Arrays.sort(A);
        if(DEBUG){
            for(int i=0;i<A.length;i++){
                System.out.println(A[i]);
            }
        }
        int ans=0,prenum=A[0],nownum,platnum=0;
        for(int i=1;i<A.length;i++){
            if(DEBUG){
                System.out.println(i+"th:");
            }
            nownum=A[i];
            if(nownum==prenum){
                platnum++;
                if(DEBUG){
                    System.out.println("Same!Platnum="+platnum);
                }
            }else{
                int height=nownum-prenum;
                if(DEBUG){
                    System.out.println("Change!height="+height+",platnum="+platnum);
                }
                if(height>platnum){
                    ans+=(1+platnum)*platnum/2;
                    platnum=0;
                }else{
                    ans+=(1+height-1)*(height-1)/2;
                    platnum-=height-1;
                    ans+=platnum*height;
                }
                if(DEBUG){
                    System.out.println("ans="+ans+",platnum="+platnum);
                }
            }
            prenum=nownum;
        }
        ans+=(1+platnum)*platnum/2;
        return ans;
    }
}