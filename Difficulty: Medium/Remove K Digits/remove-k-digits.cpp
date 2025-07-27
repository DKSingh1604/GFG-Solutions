class Solution {
  public:
    string removeKdigits(string s, int k) {
        // code here
        
        string result;
        
        
        for(char digit : s){
            while(!result.empty() && k > 0 && result.back() > digit){
                result.pop_back();
                k--;
            }
            result.push_back(digit);
        }
        
        while(k-- > 0 && !result.empty()){
            result.pop_back(); 
        }
        
        int count = 0;
        while(count < result.size() && result[count] == '0'){
            count++;
        }
        
        string finalResult = result.substr(count);
        
        return finalResult.empty() ? "0" : finalResult;
        
    }
};