class Solution {
  public:
    bool isPalindrome(int n) {
        // code here
        if(n >= 0 && n < 10) return true;
        if(n < 0) n = -1 * n;
        vector<int> numberToVector;
        while(n > 0){
            int digit = n % 10;
            numberToVector.push_back(digit);
            n = n / 10;
        }
        int m = numberToVector.size();
        int l = 0;
        int r = m-1;
        while(l < r){
            if(numberToVector[l] != numberToVector[r]){
                return false;
            }
            else{
                l++;
                r--;
            }
        }
        return true;
    }
};