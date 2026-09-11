class Solution {
  public:
    string encode(vector<string>& arr) {
        
        //["Hello", "World"] -> 5/:Hello5/:World
        int n = arr.size();
        string res = "";

        for(string &str : arr){
            res += to_string(str.size());
            res += '/';
            res += ':';
            res += str;
        }
        return res;
        
    }
    

    vector<string> decode(string& s) {
        
        // 5/:Hello5/:World -> ["Hello", "World"]
        vector<string> res;
        int n = s.size();
        int i = 0; 
        
        while(i < n){
            
            //read the length
            int len = 0;
            while(s[i] != '/'){
                len = len * 10 + (s[i] - '0');
                i++;
            }
            
            //omit the /:
            i+=2;
            
            //read the string
            string str = "";
            for(int j = 0; j < len; j++){
                str += s[i];
                i++;
            }
            res.push_back(str);
        }
        
        return res;
        
    }
};