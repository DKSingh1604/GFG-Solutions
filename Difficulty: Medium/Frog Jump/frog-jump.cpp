class Solution {
  public:
//   DP -> Memoization - we create a dp array and store the results there
    int solve(int n, vector<int> &dp, vector<int>& height){
        
        //base case
        if(n == 0) return 0;
        if(n == 1) return abs(height[n] - height[n-1]);
        
        //if the answer is in the dp array
        if(dp[n] != -1) return dp[n];
        
        int minusOne = solve(n-1, dp, height) + abs(height[n] - height[n-1]);
        int minusTwo = solve(n-2, dp, height) + abs(height[n] - height[n-2]);
        dp[n] = min(minusOne, minusTwo);
        return dp[n];
    }
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int> dp(n+1, -1);
        return solve(n-1, dp, height);
    }
};