
class Solution {
  public:
    bool isBalanced(string& k) {
        // code here
        
        if(k == "") return true;
        
        stack<char> given;
        
        for(int i = 0; i < k.size(); i++){
            if(k[i] == '[' || k[i] == '{' || k[i] == '('){
                given.push(k[i]);
            }
            else{
                if(!given.empty()){
                    if(k[i] == ')' && given.top() == '(') given.pop();
                    
                    else if(k[i] == '}' && given.top() == '{') given.pop();
                    
                    else if(k[i] == ']' && given.top() == '[') given.pop();
                    
                    else return false;
                }
                else {
                    return false;
                } 
            }
            
        }
        
        if(given.empty()) return true;
        else return false;
        
    }
};