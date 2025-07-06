
class Solution {
  public:
    // Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n) {
        // Your code here
        
        for(int i = 0; i < n; i++){
            if(arr[i] == 0){
                arr[i] = -1;
            }
        }
        
        map<int, int> mp;
        mp[0] = 1;
        int prefixSum = 0;
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            
            prefixSum += arr[i];
            
            if(mp.find(prefixSum) != mp.end()){//have found
                mp[prefixSum]++;            
                
            }
            else{
                //not found
                mp[prefixSum] = 1;
            }
            
        }
        
        
        auto it = mp.begin();
        while(it != mp.end()){
            ans += it->second * (it->second - 1)/2;    
            ++it;
        }
        return ans;
        
        
        
    }
};