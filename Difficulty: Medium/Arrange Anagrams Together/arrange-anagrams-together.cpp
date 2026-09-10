class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
        vector<vector<string>> res;
        unordered_map<string, int> mp;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            string s = arr[i];
            sort(s.begin(), s.end());
            
            
            if(mp.find(s) == mp.end()){
                mp[s] = res.size();
                res.push_back({});
            }
            res[mp[s]].push_back(arr[i]);
        }
        return res;
        
    }
};