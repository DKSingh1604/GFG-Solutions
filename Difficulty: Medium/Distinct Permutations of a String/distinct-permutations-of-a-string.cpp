class Solution {
  public:
    vector<string> ans;
    
    void solve(int index, string &s){
        
        //base case
        if(index >= s.size()) {
            ans.push_back(s);
            return;
        }
        set<char> used;
        
        for(int j = index; j < s.size(); j++){
            
            if(used.count(s[j])) continue;
            
            used.insert(s[j]);
            
            swap(s[j], s[index]);
            solve(index+1, s);
            swap(s[j], s[index]);
        }
    }
    vector<string> findPermutation(string &s) {
        
        ans.clear();
    
        solve(0, s);
        return ans;
    }
};
