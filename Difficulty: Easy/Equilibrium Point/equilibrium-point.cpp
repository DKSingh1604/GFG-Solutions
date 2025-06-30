class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        
        int n = arr.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
        }
        
        int left = 0;
        for(int i = 0; i < n; i++){
            int right = sum - left - arr[i];
            if(left == right) return i;
            left += arr[i];
        }
        return -1;
    }
};