// User function template for C++
class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        // code here
        
        int n = arr.size();
        
        for(int i = 0; i < n; i++){
            if(arr[i] > arr[i+1]){
                return arr[i];
            }
        }
        return 0;
    }
};