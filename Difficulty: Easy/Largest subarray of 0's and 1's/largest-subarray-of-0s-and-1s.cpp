class Solution {
  public:
    int maxLen(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        
        for(int i = 0; i < n; i++){
            if(arr[i] == 0){
                arr[i] = -1;
            }
        }
        
        
        
        map<int, int> mp; //prefixSum : index
        
        int prefixSum = 0;
        int maxLen = 0;
        
        for(int i = 0; i < n; i++){
            prefixSum += arr[i];
            if(prefixSum == 0){
                maxLen = i+1;
            }
            
            if(mp.find(prefixSum) != mp.end()){
                
                maxLen = max(maxLen, i - mp[prefixSum]); 
                
            }
            else{
                mp[prefixSum] = i;
            }
            
        }
        return maxLen;
        
    }
};