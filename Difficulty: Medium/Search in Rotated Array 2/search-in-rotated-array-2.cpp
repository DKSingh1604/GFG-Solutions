class Solution {
  public:
    bool search(vector<int>& arr, int key) {
        // Code here
        int n = arr.size();

        int low = 0;
        int high = n-1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(arr[mid] == key) return true;
            //find which side is sorted - right of mid OR left or mid
            
            else if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
                low++;
                high--;
                continue;
            }

            //if left is sorted
            else if(arr[low] <= arr[mid]){
                if(arr[low] <= key && key <= arr[mid]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }

            //if right is sorted
            else if(arr[mid] <= arr[high]){
                if(arr[mid] <= key && key <= arr[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};