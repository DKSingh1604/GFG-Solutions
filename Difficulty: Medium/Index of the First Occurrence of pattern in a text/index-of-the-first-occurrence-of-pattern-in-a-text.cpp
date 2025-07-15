// User function Template for C++

class Solution {
  public:
    int findMatching(string text, string pat) {
        // Code here
        int n = text.size();
        int m = pat.size();
        int i = 0;
        for(int i = 0; i <= n-m; i++){
            int j = 0;
            
            while(j < m && text[i+j] == pat[j]){
                j++;
            }
            if(j == m) return i;
        }
        return -1;
    }
};