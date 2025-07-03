class Solution {
  public:
    bool arraySortedOrNot(vector<int>& arr) {
        // code here
        int n = arr.size();
        if(n == 0 || n == 1) return true;
        
        for(int i = 0; i < n-1; i++){
            if(arr[i+1] < arr[i]){
                return false;
            }
        }
        return true;
    }
    
};