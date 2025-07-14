class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        // code here
        int n = s1.size();
        map<char, int> m1, m2;
        
        
        for(int i = 0; i < n; i++){
            
            if(m1.find(s1[i]) == m1.end()){
                m1[s1[i]] = i;
            }
            if(m2.find(s2[i]) == m2.end()){
                m2[s2[i]] = i;
            }
            
            
            if(m1[s1[i]] != m2[s2[i]]){
                return false;
            }
        }
        return true;
    }
};