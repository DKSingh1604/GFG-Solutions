class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        
        int n = arr.size();
        
        if(n == 1) return arr;
        int maxTill;
        vector<int> ans;
        for(int i = n-1; i >= 0; i--){
            if(i == n-1) {
                ans.push_back(arr[i]);
                maxTill = arr[i];
            }
            else{
                if(arr[i] >= maxTill){
                    ans.push_back(arr[i]);
                    maxTill = arr[i];
                }
            }
            
            
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};