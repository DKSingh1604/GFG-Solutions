class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        // Use BFS for calculating the min time
        int n = mat.size();
        int m = mat[0].size();
        
        queue<pair<int,int>> q;
        int fresh=0;
        
        // add all rotten oranges to queue
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==2){
                    q.push({i,j});
                }
                else if(mat[i][j]==1)   fresh++;
            }
        }
        if(fresh==0) return 0;
        int time =-1;
        //left cur right cur
        int dx[4] = {-1,0,1,0};
        //cur top cur down
        int dy[4] = {0,1,0,-1};
        
        // BFS
        while(!q.empty()){
            int size = q.size();
            time ++;
            while(size--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nx = x+dx[i];
                    int ny = y+dy[i];
                    if(nx>=0 && ny>=0 && nx<n && ny<m && mat[nx][ny] == 1){
                        mat[nx][ny] = 2;
                        q.push({nx,ny});
                        fresh--;
                    }
                }
            }
        }
        
        return fresh==0? time : -1;
    }
};