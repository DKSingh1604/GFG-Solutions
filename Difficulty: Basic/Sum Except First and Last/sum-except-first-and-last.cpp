class Solution {
  public:
    /*You are required to complete this method*/
    int sumExceptFirstLast(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        if(n == 2) return 0;
        if(n == 3) return arr[1];
        int sum = 0;
        
        for(int i = 1; i < n-1; i++){
            sum += arr[i];
        }
        return sum;
    }
};