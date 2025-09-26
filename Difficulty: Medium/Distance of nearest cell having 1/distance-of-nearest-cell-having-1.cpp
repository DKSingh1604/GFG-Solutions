class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> ans(n,vector<int>(m,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    ans[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        
        int dist = 0;
        
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        
        while(!q.empty()){
            int size = q.size();
            dist++;
            while(size--){
                auto top = q.front();
                q.pop();
                
                int x = top.first;
                int y = top.second;
                
                for(int i=0;i<4;i++){
                    int nx = dx[i] + x;
                    int ny = dy[i] + y;
                    if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny] == 0){
                        ans[nx][ny] = dist;
                        grid[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return ans;
    }
};