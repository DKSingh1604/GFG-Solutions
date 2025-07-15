// User function template for C++
class Solution {
  public:
    string longestCommonPrefix(vector<string> arr) {
        // your code here
        int n = arr.size();
        
        if(n == 0) return " ";
        
        if(n == 1) return arr[0];
        
        for(int i = 0; i < arr[0].size(); i++){
            char c = arr[0][i];
            
            for(int j = 1; j < n; j++){
                if(i > arr[j].size() || c != arr[j][i]){
                    return arr[0].substr(0, i);
                }
            }
            
        }
        return arr[0];
    }
};