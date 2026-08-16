class Solution {
  public:
    vector<vector<int>> triplets(vector<int> &arr) {
        // code here
        sort(arr.begin(), arr.end()); //nlogn
        
        int n = arr.size();
        
        vector<vector<int>> ans;
        
        for(int i = 0; i < n; i++){ // n
            if(i > 0  && arr[i] == arr[i-1]) continue;
            
            int j = i + 1;
            int k = n - 1;
            
            while(j < k){
                int sum = arr[i] + arr[j] + arr[k];
                
                if(sum == 0){
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    ans.push_back(temp);
                    
                    while(j < k && arr[j] == arr[j+1]){
                        j++;
                    }
                    while(j < k && arr[k] == arr[k-1]){
                        k--;
                    }
                    j++;
                    k--;
                }
                else if (sum < 0){
                    j++;
                }
                else {
                    k--;
                }
            }
        }
        return ans;
    }
};
