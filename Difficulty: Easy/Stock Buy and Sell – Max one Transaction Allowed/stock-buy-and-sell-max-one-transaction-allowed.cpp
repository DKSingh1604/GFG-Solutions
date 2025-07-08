class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int n = prices.size();
        int minPrice = INT_MAX;
        int profit = 0;
        int maxProfit = 0;
        
        for(int i = 0; i < n; i++){
            if(prices[i] < minPrice){
                minPrice = prices[i];
            }
             profit = prices[i] - minPrice;
             
             if(profit >= maxProfit){
                maxProfit = profit;
             }
        }
        return maxProfit;
    }
};
