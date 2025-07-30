
class Solution {
  public:
    string decodedString(string &s) {
        // code here
        
        stack<int> counts;
        stack<string> results;
        string current = "";
        int k = 0;
        
        for(char ch : s){
            if(isdigit(ch)){
                k = k * 10 + (ch - '0');
                
            }
            else if(ch == '['){
                counts.push(k);
                results.push(current);
                current = "";
                k = 0;
            }
            else if(ch == ']'){
                int repeat = counts.top();
                counts.pop();
                string prev = results.top();
                results.pop();
                string repeated = "";
                for(int i = 0; i < repeat; i++) repeated += current;
                current = prev + repeated;
            }
            else{
                current += ch;
            }
        }
        
        return current;
    }
};