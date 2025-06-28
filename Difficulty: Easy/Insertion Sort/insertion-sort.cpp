class Solution {
  public:
    // Please change the array in-place
    void insertionSort(vector<int>& arr) {
        // code here
        
        if(arr.size() == 1){
            return;
        }
        
        for(int i = 1; i < arr.size(); i++){
            int temp = arr[i];
            int j = i-1;
            for(; j >=0; j--){
                if(temp < arr[j]){
                    arr[j+1] = arr[j];
                }
                else{
                    break;
                }
                
            }
            arr[j+1] = temp;
            
        }
    }
};