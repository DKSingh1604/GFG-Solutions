class Solution {
	public:
	vector<vector<int>> ans;
	vector<int> ds;
	void solve(int index, int target, vector<int> &arr) {
		// 0  1  2 - indices
		// 1  2  3 - array, target - 5
		
		// base case
		if (index == arr.size()) {
			if (target == 0) {
				ans.push_back(ds);
				
			}
			return;
		}
		
		//recursive condition
		if(arr[index] <= target){
		    ds.push_back(arr[index]);
		    solve(index, target-arr[index], arr);
		    ds.pop_back();
		}
		solve(index+1, target, arr);
		
	}
	vector<vector<int>> targetSumComb(vector<int> &arr, int target) {
		// code here
		
		solve(0, target, arr);
		return ans;
		
	}
};
