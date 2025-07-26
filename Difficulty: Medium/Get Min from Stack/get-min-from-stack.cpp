class Solution {
  public:
    stack<pair<int, int>> st;
    Solution() {
        // code here
        
    }

    // Add an element to the top of Stack
    void push(int x) {
        
        // code here
        if(st.empty()){
            st.push(make_pair(x, x));
        }
        else{
            st.push(make_pair(x, min(x, st.top().second)));
        }
    }

    // Remove the top element from the Stack
        
    void pop() {
        // code here
        if(st.empty()){
            return;
            
        }
        else{
            st.pop();
        }
    }

        
    // Returns top element of the Stack
    int peek() {
        // code here
        if(st.empty()){
            return -1;
        }
        else{
            return st.top().first;
        }
    }
        

    // Finds minimum element of Stack
    int getMin() {
        // code here
        if(st.empty()){
            return -1;
        }
        else{
            return st.top().second;
        }
        
    }
};