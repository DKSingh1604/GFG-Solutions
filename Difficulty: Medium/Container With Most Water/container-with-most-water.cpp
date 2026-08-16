class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        if(n == 1) return 0;
        int area = INT_MIN;
        int l = 0;
        int r = n-1;
        
        while(l <= r){
            int height = min(arr[l], arr[r]);
            int base = r - l;
            
            if(height * base >= area){
                area = height * base;
                
            }
            
            if(arr[l] <= arr[r]){
                l++;
            }
            else{
                r--;
            }
        
        }
        return area;
        
    }
};