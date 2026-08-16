class Solution {
  public:
    
    int findMin(vector<int>& arr) {
        // code here
        int n = arr.size();
        int low = 0;
        int high = n-1;
        
        //ALGO
        int mini = INT_MAX;
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            //if left half is sorted, pick the minimom from the left half
            if(arr[low] <= arr[mid]){
                mini = min(mini, arr[low]);
                low = mid + 1;
            }
            // if right half is sorted, find the min from the right half
            else if(arr[mid] <= arr[high]){
                mini = min(mini, arr[mid]);
                high = mid-1;
            }
        }
        return mini;
        
    }
};