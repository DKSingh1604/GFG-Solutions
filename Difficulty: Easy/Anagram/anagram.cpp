class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        // code here
        int s1_l = s1.length();
        int s2_l = s2.length();
        
        if(s1_l != s2_l){
            return false;
        }
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        
        for(int i = 0; i < s1.length(); i++){
            if(s1[i] != s2[i]){
                return false;
            }
        }
        return true;
    }
};