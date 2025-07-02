class Solution {
  public:
    int missingNumber(vector<int>& arr) {
        // Code here
        int n = arr.size();
        
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        
        
        
        
        int actualSum = (n+2)*(n + 1)/2;
        
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
        }
        int ans = actualSum - sum ;
        return ans;
        
    }
};