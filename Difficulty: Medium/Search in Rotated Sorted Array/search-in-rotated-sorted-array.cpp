class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // Code Here
        int n = arr.size();
        
        int low = 0;
        int high = n-1;
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            if(arr[mid] == key) return mid;
            //find which side is sorted - right of mid OR left or mid
            
            //if left is sorted
            if(arr[low] <= arr[mid]){
                if(arr[low] <= key && key <= arr[mid]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            
            //if right is sorted
            if(arr[mid] <= arr[high]){
                if(arr[mid] <= key && key <= arr[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};