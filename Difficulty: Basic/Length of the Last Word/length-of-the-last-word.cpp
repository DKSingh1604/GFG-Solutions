class Solution {
  public:
    int lastWordLen(string &s) {
        // code here
        int n = s.size();
        int count = 0;
        
        for(int i = n-1; i >= 0; i--){
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
                count++;
            }
            
            if(count > 0 && s[i] == ' '){
                break;
            }
        }
        return count;
    }
};