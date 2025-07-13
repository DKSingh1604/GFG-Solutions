// User function template for C++
class Solution {
  public:

    string removeVowels(string& s) {
        // Your code goes here
        
        string ans = "";
        int n = s.size();
        
        for(int i = 0; i < n; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                continue;
            }
            else{
                ans += s[i];
            }
        }
        return ans;
    }
};