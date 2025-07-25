class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
    
        for(int i = n - 1; i >= 0; i--) {
            // Clean up smaller or equal elements
            while(!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }
    
            // If stack is empty, no greater element
            ans[i] = st.empty() ? -1 : st.top();
    
            // Push current element to stack for future comparisons
            st.push(arr[i]);
        }
    
        return ans;
        
    }
};