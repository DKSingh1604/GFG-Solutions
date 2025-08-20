
class Solution {
  public:
    bool isMaxHeap(int arr[], int n) {
        // Your code goes here
        for(int i=0;i<n/2;i++)
            if(arr[2*i+1]>arr[i] || arr[2*i+2]>arr[i])return false;
            
        return true;
    }
};