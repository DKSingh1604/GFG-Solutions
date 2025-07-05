class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        
        map<int, int> mpp;
        
        for(int i = 0; i < n; i++){
            int have = arr[i];
            int want = target - have;
            
            if(mpp.find(want) != mpp.end()){
                return true;
            }
            mpp[have] = i;
            
        }
        return false;
    }
};