class Solution {
  public:
    string longestPalindrome(string &s) {
        // code here
        int n = s.size();
        
        
        if(n == 0) return "";
        
        int start = 0;
        int maxLen = 1;
        
        for(int i = 0; i < n; i++){
            
            //for odd palindrome
            int l = i, r = i;
            while(l >= 0 && r < n && s[l] == s[r]){
                if(r-l+1 > maxLen){
                    start = l;
                    maxLen = r-l+1;
                }
                l--;
                r++;
            }
            
            //for even plaindrome
            l = i, r = i+1;
            while(l >= 0 && r < n && s[l] == s[r]){
                if(r-l+1 > maxLen){
                    start = l;
                    maxLen = r-l+1;
                }
                l--;
                r++;
            }
        }
        return s.substr(start, maxLen);
    }
};