class Solution {
  public:
    vector<vector<int>> fourSum(vector<int> &arr, int target) {
        // code here
        sort(arr.begin(), arr.end()); //nlogn
        int n = arr.size();
        vector<vector<int>> res;
        for(int i = 0; i < n; i++){ //n
            if(i > 0 && arr[i] == arr[i-1]) continue;
            for(int j = i+1; j < n; j++){ //n
                if(j > i+1 && arr[j] == arr[j-1]) continue;
                int k = j + 1;
                int l = n-1;
                
                while(k < l){//n
                    int sum = arr[i] + arr[j] + arr[k] + arr[l];
                    
                    if(sum == target){
                        vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                        res.push_back(temp);
                        
                        while(k < l && arr[k] == arr[k+1]){
                            k++;
                        }
                        while(k < l && arr[l] == arr[l-1]){
                            l--;
                        }
                        k++;
                        l--;
                    }
                    else if(sum < target){
                        k++;
                    }
                    else{
                        l--;
                    }
                }
            }
        }
        return res;
    }
};