class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        if (n == 0 || n == 1) return ;
        int s = 0;
        int e = n-1;
        
        while(s <= e){
            swap(arr[s++], arr[e--]);
        }
    }
};