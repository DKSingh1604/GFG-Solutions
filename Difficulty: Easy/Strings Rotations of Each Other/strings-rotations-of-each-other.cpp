class Solution {
  public:
    
    bool areRotations(string &s1, string &s2) {
        
        if (s1.length() != s2.length()) {
            return false;
        }
        std::string combined = s1 + s1;
        return combined.find(s2) != std::string::npos;
            
        
        
        
        
    }
};