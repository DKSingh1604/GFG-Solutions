class Solution {
  public:
    int minCandy(vector<int> &arr) {
        // code here
        int n = arr.size();
        int count = 0;
        int left[n];
        int right[n];
        left[0] = 1;
        right[n-1] = 1;
        int ans[n];
        
        //fill the left array
        for(int i = 1; i < n; i++){
            if(arr[i] > arr[i-1]) left[i] = left[i-1] + 1;
            else left[i] = 1;
        }
        
        //fill the right array
        for(int i = n-2; i >= 0; i--){
            if(arr[i] > arr[i+1]) right[i] = right[i+1] + 1;
            else right[i] = 1;
        }
        
        for(int i = 0; i< n; i++){
            ans[i] = max(left[i], right[i]);
        }
        
        for(int i = 0; i < n; i++){
            count += ans[i];
        }
        
        return count;
    }
};
