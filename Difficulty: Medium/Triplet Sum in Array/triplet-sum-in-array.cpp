class Solution {
	public:
	bool hasTripletSum(vector<int> &arr, int target) {
		// Code Here
		sort(arr.begin(), arr.end());
		int n = arr.size();
		
		vector<vector<int>> res;
		
		for (int i = 0; i < n; i++) {
			if (i > 0 && arr[i] == arr[i - 1])
				continue;
			
			int j = i + 1;
			int k = n - 1;
			
			while (j < k) {
				
				int sum = arr[i] + arr[j] + arr[k];
				
				if (sum == target) {
					vector<int> triplet = {arr[i], arr[j], arr[k]};
					return true;
					res.push_back(triplet);
					
					while (j < k && arr[j] == arr[j + 1]) {
						j++;
					}
					while (j < k && arr[k] == arr[k - 1]) {
						k--;
					}
					j++;
					k--;
				}
				
				else if (sum < target) {
					j++;
				}
				else {
					k--;
				}
			}
			
		}
		return false;
	}
};
