class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int n = arr.size();
        int h = -1;
        int sh = -1;
        for(int i = 0; i < n; i++){
            if(arr[i] > h){
                sh = h;
                h = arr[i];
            }
            else if(arr[i] > sh && arr[i] < h){
                sh = arr[i];
            }
        }
        return sh;
        
    }
};