class Solution {
	
	public:
	void generatePermutations(string &s, string current_permutation,
	int index, vector<string> &result) {
		
		if(index == s.size()){
		    result.push_back(current_permutation);
		    return;
		}
		
		generatePermutations(s, current_permutation + s[index], index + 1, result);
		
		generatePermutations(s, current_permutation + " " + s[index], index + 1, result);
		
		
	}
	vector<string> permutation(string s) {
		// code here
		vector<string>result;
		
		if (s.empty())
			return result;
		
		generatePermutations(s, string(1, s[0]), 1, result);
		
		sort(result.begin(), result.end());
		
		return result;
	}
};
