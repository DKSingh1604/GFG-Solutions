class Solution {
  public:
    int evaluate(vector<string>& arr) {
        // code here
        
        int n = arr.size();
        
        stack<int> st;
        for(int i = 0; i < n; i++){
            if(arr[i] != "+" && arr[i] != "-" && arr[i] != "*" && arr[i] != "/"){
                //a number string
                st.push(stoi(arr[i]));
                
            }
            else{
                int temp1;
                int temp2;
                //an operator
                if(!st.empty()){
                    temp1 = st.top();
                    st.pop();
                }
                
                if(!st.empty()){
                    temp2 = st.top();
                    st.pop();
                }
                
                if(arr[i] == "+"){
                    st.push(temp2 + temp1);
                }
                else if(arr[i] == "-"){
                    st.push(temp2 - temp1);
                }
                else if(arr[i] == "*"){
                    st.push(temp2 * temp1);
                }
                else{
                    st.push(temp2 / temp1);
                }
            }
        }
        return st.top();
    }
};