
class Solution {
  public:

    string modify(string& s) {
        // your code here
        int n = s.size();
        
        if(islower(s[0])){
            for(int i = 0; i < n; i++){
                s[i] = tolower(s[i]);
            }
        }
        else {
            for(int i = 0; i < n; i++){
                s[i] = toupper(s[i]);
            }
        }
        
        return s;
    }
};