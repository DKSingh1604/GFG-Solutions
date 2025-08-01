class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        // code here
        if(k > q.size()) return q;
        
        
        stack<int> st;
        queue<int> ans_q;
        
        
        int count = 0;
        while(!q.empty() && count < k){
            st.push(q.front());
            q.pop();
            count++;
        }
        
        while(!st.empty()){
            ans_q.push(st.top());
            st.pop();
        }
        while(!q.empty()){
            ans_q.push(q.front());
            q.pop();
        }
        
        return ans_q;
        
        
    }
};