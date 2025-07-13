class Solution {
  public:
    // Function to check if a string is a palindrome.
    bool isPalindrome(string& s) {
        // code here
        
        int n = s.size();
        
        if(n == 1 || n == 0) return true;
        int l = 0;
        int r = n-1;
        
        while(l <= r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
        
    }
};