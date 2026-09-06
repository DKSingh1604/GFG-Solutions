class Solution {
  public:
    int longestSubstr(string& s, int k) {
        // code here
        int n = s.size();
        if(n == 0 || n == 1) return n;
        
        
        int maxLen = 1;
        int maxFreq = 1;
        int l = 0;
        int r = 0;
        vector<int> hashArray(26, 0);
        
        while(r < n){
            // if the substring is a valid substring
            
            hashArray[s[r] - 'A']++;
            maxFreq = max(maxFreq, hashArray[s[r] - 'A']);
            //if not valid
            while((r-l+1) - maxFreq > k){ //1-1 = 0, true,
                int len = r-l+1;
                hashArray[s[l] - 'A']--;
                maxFreq = 0;
                for(int i = 0; i < 26; i++){
                    maxFreq = max(maxFreq, hashArray[i]);
                }
                l++;
                
            }
            //if valid
            if(r-l+1 - maxFreq <= k){
                
                maxLen = max(maxLen, r-l+1);
            }
            r++;
            
        }
        return maxLen;
    }
};