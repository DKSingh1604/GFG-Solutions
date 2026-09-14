class Solution {
	public:
	void solve(int index, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
	    
	    //base case
	    if(index == arr.size()){
	        if(target == 0){
	            ans.push_back(ds);
	        }
	        return;
	    }
	    
	    //pick up the element
	    if(arr[index] <= target){
	        ds.push_back(arr[index]);
	        solve(index, target - arr[index], arr, ans, ds);
	        ds.pop_back();
	    }
	    
	    solve(index+1, target, arr, ans, ds);
	    
	}
	vector<vector<int>> targetSumComb(vector<int> &arr, int target) {
		// code here
		vector<vector<int>> ans;
		vector<int> ds;
		solve(0, target, arr, ans, ds);
		return ans;
	}
};
