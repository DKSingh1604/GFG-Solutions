class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        long l = arr.size();
        long n = l + 1;
        
        long sum = n*(n+1)/2;
        
        long arrSum = 0;
        for(int i = 0; i < l; i++){
            arrSum += arr[i];
        }
        
        long element = sum - arrSum;
        return element;
        
        
        
    }
};