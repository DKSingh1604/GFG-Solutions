// User function Template for C++

class Solution {
  public:
    int checkCompressed(string S, string T) {
        // code here
        int n = S.length();
        int m = T.length();
        
        int count;
        int i = 0;
        int j = 0;
    
        
        while (j < m) {
        if (isdigit(T[j])) {
            int num = 0;
            while (j < m && isdigit(T[j])) {
                num = num * 10 + (T[j] - '0');
                j++;
            }
            i += num; // skip 'num' characters in S
        } else {
            if (i >= n || S[i] != T[j]) return false;
            i++;
            j++;
        }
    }
        
        return i == n;
           
        
    }
};
