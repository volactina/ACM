class Solution {
    public int lengthOfLIS(int[] nums) {
        /*
            f(n)表示以nums[n]结尾的最长上升子序列长度
            f(n)=Max(f(k))+1,其中nums[n]>nums[k]
            O(n^2)
        */
        if(nums.length==0) return 0;
        int[] f=new int[nums.length];
        f[0]=1;
        int ans=1;
        for(int i=1;i<nums.length;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    f[i]=Math.max(f[i],f[j]);
                }
            }
            f[i]++;
            ans=Math.max(ans,f[i]);
        }
        return ans;
    }
}