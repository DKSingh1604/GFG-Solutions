class Solution {
  public:
    bool isPalindrome(int n) {
        // code here
        if(n >= 0 && n < 10) return true;
        if(n < 0) n = -1 * n;
        
        int original = n;
        int rev = 0;
        
        while(n > 0){
            rev = rev * 10 + n % 10;
            n /= 10;
        }
        return original == rev;
    }
};