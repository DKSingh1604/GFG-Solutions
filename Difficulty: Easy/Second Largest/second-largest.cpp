// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        
        int max1 = 1;
        int max2 = 1;
        
        for(int i = 0; i < n; i++){
            if(arr[i] > max1){
                max2 = max1;
                max1 = arr[i];
                
            }
            else if((arr[i] < max1 && arr[i] > max2) ){
                max2 = arr[i];
            }
            
        }
        if(max2 == 1){
            return -1;
        }
        else {
            return max2;
        }
        
        
        
    }
};