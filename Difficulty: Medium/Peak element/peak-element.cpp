class Solution {
  public:
    int peakElement(vector<int> &arr) {
        // code here
        int n = arr.size();
        if(n == 1) return 0;
        if(arr[0] > arr[1]) return 0;
        
        for(int i = 1; i < n; i++){
            if(i == n-1){
                continue;
            }
            
            if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){
                return i;
            }
        }
        return n-1;
    }
};