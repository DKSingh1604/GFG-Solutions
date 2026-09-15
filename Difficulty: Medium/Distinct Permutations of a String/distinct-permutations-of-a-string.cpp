class Solution {
	public:
	vector<string> ans;
	void solve(int index, string &s) {
		
		// base case
		if (index >= s.size()) {
			ans.push_back(s);
			return;
		}
		set<char> used;
		
		for (int i = index; i < s.size(); i++) {
			
			if (used.count(s[i])) {
				continue;
			}
			
			used.insert(s[i]);
			
			swap(s[i], s[index]);
			solve(index + 1, s);
			// bactracking - so the string remains the same for next iteration
			swap(s[i], s[index]);
		}
		
	}
	
	vector<string> findPermutation(string &s) {
		// Code here
		ans.clear();
		solve(0, s);
		return ans;
		
	}
};
