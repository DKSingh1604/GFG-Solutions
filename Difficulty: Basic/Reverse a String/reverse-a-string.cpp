// User function Template for C++
class Solution {
  public:
    string reverseString(string& s) {
        // code here
        int n = s.length();
        if(n == 1){
            return s;
        }
        
        int start = 0;
        int end = n-1;
        
        while(start <= end){
            swap(s[start++], s[end--]);
            
        }
        return s;
    }
};
