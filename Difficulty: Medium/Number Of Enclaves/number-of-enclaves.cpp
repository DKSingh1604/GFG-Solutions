// User function Template for C++

class Solution {
  public:
    void dfs(int n, int m, int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis){
        
        vis[row][col] = 1;
        
        //check for adjacent cells
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        
        for(int i = 0; i < 4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                dfs(n, m, nrow, ncol, grid, vis);
            }
        }
        
    }
    
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        //traverse first row and last row
        for(int j = 0; j < m; j++){
            //first row
            if(!vis[0][j] && grid[0][j] == 1){
                dfs(n, m, 0, j, grid, vis);
            }
            
            
            //last row
            if(!vis[n-1][j] && grid[n-1][j] == 1){
                dfs(n, m, n-1, j, grid, vis);
            }
        }
        
        //traverse first col and last col
        for(int i = 0; i < n; i++){
            //first col
            if(!vis[i][0] && grid[i][0] == 1){
                dfs(n, m, i, 0, grid, vis);
            }
            
            //last col
            if(!vis[i][m-1] && grid[i][m-1]){
                dfs(n, m, i, m-1, grid, vis);
            }
        }
        
        //traverse the whole grid
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    count++;
                    vis[i][j] = 1;
                }
            }
        }
        
        return count;
    }
};
