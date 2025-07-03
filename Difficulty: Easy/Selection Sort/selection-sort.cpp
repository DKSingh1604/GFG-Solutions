class Solution {
  public:
    // Function to perform selection sort on the given array.
    void selectionSort(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        if(n == 0 || n == 1) return ;
        
        int k;
        int minEl;
        
        for(int i = 0; i < n; i++){
            minEl = 10000000;
            for(int j = i; j < n; j++){
                
                if(arr[j] < minEl){
                    minEl = arr[j];
                    k = j;
                }
                
            }
            swap(arr[i], arr[k]);
        }
    }
};