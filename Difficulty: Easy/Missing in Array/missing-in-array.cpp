class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        long long n = arr.size();
        long long currSum = 0;
        
        //SUM OF CURRENT ARRAY
        for(int i = 0; i < n; i++){
            currSum += arr[i];            
        }
        
        //SUM OF ARRAY WITH N NUMBERS FROM 1 TO N
        long long greaterSum = (n+1)*(n+2)/2;
        
        long long ans = greaterSum - currSum;
        return ans;
        
    }
};