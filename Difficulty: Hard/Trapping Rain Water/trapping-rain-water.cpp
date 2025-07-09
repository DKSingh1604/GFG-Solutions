class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        int leftMax = 0;
        int rightMax = 0;
        int totalWater = 0;
        
        int left = 0;
        int right = n-1;
        while(left <= right){
            if(arr[left] <= arr[right]){
                if(arr[left] > leftMax){
                    leftMax = arr[left];
                }
                else{
                    totalWater += leftMax - arr[left];
                    left++;
                }
            }
            else{
                if(arr[right] > rightMax){
                    rightMax = arr[right];
                }
                else{
                    totalWater += rightMax - arr[right];
                    right--;
                }
            }
        }
        return totalWater;
    }
};