class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        //sum[i]=A[0]+...+A[i-1]
        int[] sum=new int[50001];
        for(int i=0;i<A.length;i++) sum[i+1]=sum[i]+A[i];
        if(sum[A.length]%3!=0) return false;
        int target=sum[A.length]/3;
        //sum1:0..i,sum2:i+1..j,sum3:j+1..len-1
        for(int i=0;i<A.length-2;i++){
            int sum1=sum[i+1];
            if(sum1!=target) continue;
            for(int j=i+1;j<A.length-1;j++){
                int sum2=sum[j+1]-sum1;
                if(sum2==target) return true;
            }
        }
        return false;
    }
}