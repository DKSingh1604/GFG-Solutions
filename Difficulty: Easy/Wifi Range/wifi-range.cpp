class Solution {
  public:
    bool wifiRange(string &s, int x) {
        // code here
        int n = s.length();
        
        if(n == 0) return true;
        
        vector<int> diff(n+1, 0);
        
        for(int k = 0; k < n; k++){
            if(s[k] == '1'){
                int start_coverage = max(0, k-x);
                int end_coverage = min(n-1, k+x);
                
                diff[start_coverage]++;
                
                if(end_coverage + 1 <= n){
                    diff[end_coverage + 1]--;
                }
            }
        }
        
        int current_coverage_count = 0;
        for(int i = 0; i < n; ++i){
            current_coverage_count += diff[i];
            
            if(current_coverage_count == 0) return false;
        }
        return true;
    }    
    
};