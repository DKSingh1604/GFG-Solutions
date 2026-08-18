class Solution {
  public:
    int peakElement(vector<int> &arr) {
        // code here
        
        //Applying BINARY SEARCH
        
        int n = arr.size();
        //if the array has only 1 element OR the first element is the peak
        if((n == 1) || (arr[0] > arr[1])) return 0;
        
        //if the last element is the peak
        if(arr[n-1] > arr[n-2]) return n-1;
        
        int l = 1;
        int r = n-2;
        
        while(l <= r){
            int mid  = l + (r-l)/2;
            
            //base case - if mid is the peak
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) return mid;
            
            //if the peak is to the right of mid
            if(arr[mid] > arr[mid-1]){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        return n-1;
        
    }
};