// Function to locate the occurrence of the string x in the string s.
class Solution {
  public:
    int firstOccurence(string &txt, string &pat) {
        // Your code here
        int t = txt.length();
        int p = pat.length();
        
        if(p > t) return -1;
        
        for(int i = 0; i <= t-p; i++){
            int j;
            for(j=0; j < p; j++){
                if(txt[i+j] != pat[j]){
                    break;
                }
            }
            if(j == p) return i;
        }
        return -1;
    }
    
};