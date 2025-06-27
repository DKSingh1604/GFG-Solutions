class Solution {
  public:
    // int findMax(vector<int>& arr, int s, int e){
        
        
    //     int max = INT_MIN;
    //     for(int i = s; i <= e; i++){
    //         if(arr[i] >= max){
    //             max = arr[i];
    //         }
    //     }
    //     return max;
    // }
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        
        if(k == 1){
            return arr;
        }
        vector<int> ans;
        int n = arr.size();
        
        int a = 0;
        int b = 0;
        map<int, int> freq;
        
        while(b < k){
            freq[arr[b]]++;
            b++;
        }
        
        while(b < arr.size()){
            
            ans.push_back(freq.rbegin() -> first);
            freq[arr[a]]--;
            if(freq[arr[a]] == 0){
                freq.erase(arr[a]);
            }
            freq[arr[b]]++;
            
            a++;
            b++;
        }
        ans.push_back(freq.rbegin() -> first);
        return ans;
        
        
        
    }
};