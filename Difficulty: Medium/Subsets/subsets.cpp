class Solution {
  public:
    vector<vector<int>> res;
    void solve(int i, vector<int> &arr, vector<int> &current){
        
        if(i == arr.size()){
            res.push_back(current);
            return;
        }
        else{
            solve(i+1, arr, current);
            current.push_back(arr[i]);
            solve(i+1, arr, current);
            current.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& arr) {
        // code here
        vector<int> subset;
    
        solve(0, arr, subset);
        
        return res;
    }
};