class Solution {
    public int massage(int[] nums) {
        //f[i]=max(f[i-2],f[i-3])+nums[i]
        if(nums.length==0) return 0;
        int f[]=new int[nums.length],ans;
        f[0]=nums[0];
        if(nums.length==1){
            return f[0];
        }
        f[1]=nums[1];
        if(nums.length==2){
            return Math.max(f[0],f[1]);
        }
        f[2]=nums[0]+nums[2];
        if(nums.length==3){
            return Math.max(f[1],f[2]);
        }
        ans=Math.max(f[1],f[2]);
        for(int i=3;i<nums.length;i++){
            f[i]=Math.max(f[i-2],f[i-3])+nums[i];
            ans=Math.max(ans,f[i]);
        }
        return ans;
    }
}