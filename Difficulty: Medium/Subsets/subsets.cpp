class Solution {
	
	public:
	vector<vector<int>> ans;
	vector<int> current;
	
	void solve(int index, vector<int>& arr) {
		
		// base case
		if (index == arr.size()) {
			ans.push_back(current);
			return;
		}
		
		//recursive condition
		else{
		    solve(index+1, arr);
		    current.push_back(arr[index]);
		    solve(index+1, arr);
		    current.pop_back();
		}
	}
	
	vector<vector<int>> subsets(vector<int>& arr) {
		
		solve(0, arr);
		return ans;
		
	}
};
