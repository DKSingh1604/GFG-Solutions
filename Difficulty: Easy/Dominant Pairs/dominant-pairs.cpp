class Solution {
	public:
	int dominantPairs(vector<int> &arr) {
		int n = arr.size();
		int count = 0;
		
		sort(arr.begin() + n/2, arr.end());
		
		for(int i = 0; i < n/2; i++) {

         int low = n/2;
         int high = n;

         while(low < high) {
             int mid = low + (high - low) / 2;

             if(5LL * arr[mid] <= arr[i]) {
                 low = mid + 1;
             }
             else {
                 high = mid;
             }
         }

         count += low - n/2;
     }

		return count;
	}
};
