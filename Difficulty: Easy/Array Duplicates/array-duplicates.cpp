class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        // code here
        vector<int> ans;
        sort(arr.begin(), arr.end());
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] == arr[i-1]){
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};