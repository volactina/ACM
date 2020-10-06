class Solution {
    public int maxProfit(int[] prices) {
        int len=prices.length;
        int maxprofit=0;
        for(int i=0;i<len;i++){
            for(int j=i+1;j<len;j++){
                    if(prices[j]-prices[i]>maxprofit) maxprofit=prices[j]-prices[i];
            }
        }
        return maxprofit;
    }
}