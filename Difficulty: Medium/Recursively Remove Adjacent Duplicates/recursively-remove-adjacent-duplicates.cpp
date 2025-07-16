// User function template for C++

class Solution {
  public:
    string removeUtil(string &s) {
        // code here
        
        int n = s.size();
        
        if(n <= 1) return s; 
        
        string result = "";
        int i = 0;
        bool found = false;
        
        while(i < n){
            if(i < n-1 && s[i] == s[i+1]){
                found = true;
                char ch = s[i];
                while(i < n && s[i] == ch) i++;
            }
            else{
                result += s[i];
                i++;
            }
        }
        
        if(found) return removeUtil(result);
        else return result;
    }    
};