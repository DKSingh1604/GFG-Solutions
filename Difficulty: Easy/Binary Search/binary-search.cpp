class Solution {
  public:
    int binarysearch(vector<int> &arr, int k) {
        // code here
        int n =  arr.size();
        int s = 0;
        int e = n-1;
        int minInd = -1;
        while(s <= e){
            int mid = s + (e-s)/2;
            if(arr[mid] == k){
                minInd = mid;
                e = mid - 1;
            }
            else if(k > arr[mid]){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
            
        }
        return minInd;
    }
};