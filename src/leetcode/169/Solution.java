class Solution {
    public int majorityElement(int[] nums) {
        HashMap mp=new HashMap();
        int maxnum=nums[0],maxcnt=0;
        for(int i=0;i<nums.length;i++){
            int cnt=1;
            if(mp.containsKey(nums[i])){
                cnt+=(int)mp.get(nums[i]);
            }
            mp.put(nums[i],cnt);
            if(cnt>maxcnt){
                maxcnt=cnt;
                maxnum=nums[i];
            }
        }
        return maxnum;
    }
}