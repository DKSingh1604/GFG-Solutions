class Solution {
  public:
    int removeDuplicates(vector<int> &arr) {
        // code here
        int n = arr.size();
        int l = 0;
        
        for(int r = l+1; r < n; r++){
            if(arr[r] != arr[l]){
                l++;
                arr[l] = arr[r];
                
            }
        }
        return l+1;
        
    }
};