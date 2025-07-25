class Solution {
  public:
    string reverse(const string& S) {
        // code here
        string ans = "";
        stack<char> inter;
        
        for(int i = 0; i < S.size(); i++){
            inter.push(S[i]);
        }
        
        while(!inter.empty()){
            ans += inter.top();
            inter.pop();
        }
        
        return ans;
    }
};