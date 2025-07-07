class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        int n = arr.size();
        int maxProd = INT_MIN;
        int prefix = 1, suffix = 1;
    
        for (int i = 0; i < n; i++) {
            prefix *= arr[i];
            suffix *= arr[n - 1 - i];
    
            maxProd = max({maxProd, prefix, suffix});
    
            if (prefix == 0) prefix = 1;
            if (suffix == 0) suffix = 1;
        }
    
        return maxProd;
        
    }
};