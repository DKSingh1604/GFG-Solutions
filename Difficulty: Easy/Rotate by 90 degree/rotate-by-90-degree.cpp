
class Solution {
  public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        
        
        for(int i = 0; i <= n - 1; i++){
            for(int j = i + 1; j < n; j++){
                swap(mat[i][j], mat[j][i]);
            }
        }
        
        for(int j = 0; j < n ; j++){
            int i = 0;
            int k = n - 1;
            while(i < k){
                swap(mat[i][j], mat[k][j]);
                i++;
                k--;
            }
            
        }
        
    }
};
