class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> prefixSum(n);
        prefixSum[0] = arr[0];
        
        vector<int> postfixSum(n);
        postfixSum[n-1] = arr[n-1];        
        
        for(int i = 1, j = n-2; i < n && j >= 0; i++, j--){
            prefixSum[i] = prefixSum[i-1] * arr[i];
            postfixSum[j] = postfixSum[j+1] * arr[j];
        }
        
        vector<int> output(n);
        for(int i = 0; i< n; i++){
            if(i == 0){
                output[i] = 1 * postfixSum[i+1];
            }
            else if(i == n-1){
                output[i] = 1 * prefixSum[i-1];
            }
            else{
                output[i] = prefixSum[i-1] * postfixSum[i+1];
            }
                    
        }
        
        return output;
    }
};
