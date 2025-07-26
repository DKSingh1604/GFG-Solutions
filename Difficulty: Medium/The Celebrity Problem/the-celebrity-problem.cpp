class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        stack<int> st;
        int n = mat.size();
        for(int i = 0; i < n; i++){
            st.push(i);
        }
        
        while(st.size() > 1){
            int A = st.top();
            st.pop();
            int B = st.top();
            st.pop();
            
            if(mat[A][B] == 1){
                st.push(B);
            }
            else{
                st.push(A);
            }
        }
        
        int potential = st.top();
        
        for(int i = 0; i < n; i++){
            if(i == potential) continue;
            if(mat[potential][i] == 1 || mat[i][potential] == 0){
                return -1;
            }
        }
        
        return potential;
    }
    
};