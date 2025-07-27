class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        
        int n = arr.size();
        
        vector<int> ans;
        
        if(n == 1){
            ans.push_back(-1);
            return ans;
        }
        
        stack<int> st;
        
        for(int i = n-1; i >= 0; i--){
            if(i == n-1){
                st.push(arr[i]);
                ans.push_back(-1);
            }
            else{
                if(st.top() <= arr[i]){
                    while(!st.empty() && st.top() <= arr[i]){
                        st.pop();
                    }
                    if(st.empty()){
                        ans.push_back(-1);
                    }
                    else{
                        ans.push_back(st.top());
                    }
                    st.push(arr[i]);
                }
                else{
                    ans.push_back(st.top());
                    st.push(arr[i]);
                }
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};