class Solution {
  public:
    int thirdLargest(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        if(n <= 2) return -1;
        
        int first = 0, second = 0, third = 0;
        
        for(int i = 0; i < n; i++){
            if(arr[i] >= first){
                third = second;
                second = first;
                first = arr[i];
            }
            else if(arr[i] >= second){
                third = second;
                second = arr[i];
            }
            else if(arr[i] >= third){
                third = arr[i];
            } 
            
        }
        return third;
        
    }
};