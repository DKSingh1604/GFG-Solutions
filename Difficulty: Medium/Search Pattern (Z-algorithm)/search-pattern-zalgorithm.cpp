class Solution {
  public:
    vector<int> search(string pat, string txt) {
        // code hee.
        vector<int> ans;
        int n = txt.size();
        int m = pat.size();
        
        for(int i = 0; i <= n-m; i++){
            int j = 0;
            while(j < m && txt[i+j] == pat[j]){
                j++;
            }
            if(j == m) ans.push_back(i+1);
        }
        
        if(ans.empty()) return {-1};
        
        return ans;
        
    }
};