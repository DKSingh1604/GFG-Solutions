class Solution {
  public:
  int getMaxArea(vector<int> &arr) {
        
        int n = arr.size();
        stack<int> st;
        int maxArea = 0;
        
        for(int i = 0; i <= n; i++){
            int currHeight = (i == n) ? 0 : arr[i];
            
            while(!st.empty() && currHeight < arr[st.top()]){
                int height = arr[st.top()];
                st.pop();
                
                int width = (st.empty()) ? i : i - st.top() - 1;
                
                int area = height * width;
                
                maxArea = max(maxArea, area);
            }
            st.push(i);
        }
        
        return maxArea;
        
    }
    
    int maxArea(vector<vector<int>> &mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        vector<int> hist(m, 0);
        int maxiArea = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                hist[j] = (mat[i][j] == 0) ? 0 : hist[j] + 1;
            }
            
            maxiArea = max(maxiArea, getMaxArea(hist));
        }
        
        return maxiArea;
        
    }
};