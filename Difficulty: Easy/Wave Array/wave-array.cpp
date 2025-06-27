class Solution {
  public:
    // arr: input array
    // Function to sort the array into a wave-like array.
    void convertToWave(vector<int>& arr) {
        // code here
        if(arr.size() == 1){
            return;
        }
        for(int i = 0; i < arr.size(); i = i + 2){
            if(i == arr.size() - 1){
                return;
            }
            else{
                swap(arr[i], arr[i+1]);
            }
            
        }
        
    }
};