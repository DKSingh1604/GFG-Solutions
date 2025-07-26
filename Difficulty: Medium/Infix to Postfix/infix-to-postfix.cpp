class Solution {
  public:
    int precedence(char op){
        if(op == '^') return 3;
        else if(op == '*' || op == '/') return 2;
        else if(op == '+' || op == '-') return 1;
        else return 0;
    }
    
    string infixToPostfix(string& s) {
        string postfix = "";
        stack<char> st;
        
        for(char ch : s){
            if(isalnum(ch)){
                postfix += ch;
            }
            else if(ch == '('){
                st.push(ch);
            }
            else if(ch == ')'){
                while(!st.empty() && st.top() != '('){
                    postfix += st.top();
                    st.pop();
                }
                if(!st.empty()) st.pop(); // Pop '('
            }
            else{
                // operator
                while(!st.empty() && precedence(st.top()) >= precedence(ch)){
                    postfix += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }
        
        while(!st.empty()){
            postfix += st.top();
            st.pop();
        }
        
        return postfix;
    }
};
