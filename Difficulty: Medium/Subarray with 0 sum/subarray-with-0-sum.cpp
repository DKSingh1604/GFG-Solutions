class Solution {
  public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        
        map<int, int> mp;
        int prefixSum = 0;
        
        for(int i = 0; i < n; i++){
            prefixSum += arr[i];
            
            if(arr[i] == 0 || prefixSum == 0){
                return true;
            }
            
            if(mp.find(prefixSum) != mp.end()){
                return true;
            }
            else{
                mp[prefixSum] = i;
            }
        }
        return false;
    }
};