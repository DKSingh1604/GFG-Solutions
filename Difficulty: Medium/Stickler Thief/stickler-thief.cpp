class Solution {
  public:
    //O(n) & O(n)
    int solve(vector<int>& arr, int n, vector<int> &memo){
        
        if(n <= 0) return 0;
        if(n == 1) return arr[0];
        
        if(memo[n] != -1){
            return memo[n];
        }
        
        int pick = arr[n-1] + solve(arr, n-2, memo);
        int notPick = solve(arr, n-1, memo);
        
        return memo[n] = max(pick, notPick);
    }
    int findMaxSum(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> memo(n+1, -1);
        return solve(arr, n, memo);
    }
};