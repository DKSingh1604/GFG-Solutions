class Solution {
  public:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& grid){
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        
        int n = grid.size();
        int m = grid[0].size();
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            
            //travese the neighbours and mark the 'L' as '1's
            for(int delrow = -1; delrow <= 1; delrow++){
                for(int delcol = -1; delcol <= 1; delcol++){
                    int nrow = row + delrow;
                    int ncol = col + delcol;
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 'L' && !vis[nrow][ncol]){
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 'L' && !vis[i][j]){
                    count++;
                    bfs(i, j, vis, grid);
                }
            }
        }
        
        return count;
        
    }
};