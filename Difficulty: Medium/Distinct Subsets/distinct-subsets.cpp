class Solution {
	public:
	
	set<vector<int>> mySet;
	void solve(int i, vector<int> &arr, vector<int> &current) {
		
		if (i == arr.size()) {
			mySet.insert(current);
			
		}
		else {
			solve(i + 1, arr, current);
			current.push_back(arr[i]);
			solve(i + 1, arr, current);
			current.pop_back();
		}
		
		return;
		
	}
	vector<vector<int>> findSubsets(vector<int>& arr) {
		// code here
		mySet.clear();
		
		sort(arr.begin(), arr.end());
		vector<int> subset;
		
		solve(0, arr, subset);
		
		return vector<vector<int>> (mySet.begin(), mySet.end()); ;
	}
};
