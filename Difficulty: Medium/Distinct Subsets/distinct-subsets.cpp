class Solution {
	public:
	vector<vector<int>> ans;
	vector<int> current;
	void solve(int index, vector<int>& arr) {
		
		ans.push_back(current);
		// base case
		for (int i = index; i < arr.size(); i++) {
			if (i > index && arr[i] == arr[i - 1]) {
				continue;
			}
			current.push_back(arr[i]);
			solve(i + 1, arr);
			current.pop_back();
		}
	}
	vector<vector<int>> findSubsets(vector<int>& arr) {
		// code here
		sort(arr.begin(), arr.end()); 
		solve(0, arr);
		return ans;
		
	}
};
