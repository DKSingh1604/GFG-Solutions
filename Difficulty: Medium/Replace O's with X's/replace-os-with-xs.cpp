// User function Template for C++

class Solution {
  public:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& mat, int n, int m){
        
        vis[row][col] = 1;
        
        //checking in the 4 directions
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        
        for(int i = 0; i < 4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 'O'){
                dfs(nrow, ncol, vis, mat, n, m);
            }
        }
    }
    
    vector<vector<char>> fill(vector<vector<char>>& mat) {
        // code here
        
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
         
        //traverse first row and last row
        for(int j = 0; j < m; j++){
            //first row
            if(!vis[0][j] && mat[0][j] == 'O'){
                dfs(0, j, vis, mat, n, m);
            }
            
            //last row
            if(!vis[n-1][j] && mat[n-1][j] == 'O'){
                dfs(n-1, j, vis, mat, n, m);
            }
        }
        
        //traverse first col and last col
        for(int i = 0; i < n; i++){
            
            //first col
            if(!vis[i][0] && mat[i][0] == 'O'){
                dfs(i, 0, vis, mat, n, m);
            }
            
            //last col
            if(!vis[i][m-1] && mat[i][m-1] == 'O'){
                dfs(i, m-1, vis, mat, n, m);
            }
        }
        
        //traverse the full board
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && mat[i][j] == 'O'){
                    vis[i][j] = 1;
                    mat[i][j] = 'X';
                }
            }
        }
        
        return mat;
        
    }
};