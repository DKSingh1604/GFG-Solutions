// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        if(source.first == destination.first && source.second == destination.second){
            return 0;
        }
        vector<vector<int>> dist(n,vector<int>(m, INT_MAX));
        int srcRow = source.first;
        int srcCol = source.second;
        dist[srcRow][srcCol] = 0;
        
        queue<pair<int, pair<int, int>>> pq;
        
        pq.push({0, {srcRow, srcCol}});
        
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        
        while(!pq.empty()){
            int newDis = pq.front().first;
            int newRow = pq.front().second.first;
            int newCol = pq.front().second.second;
            pq.pop();
            
            for(int i = 0; i < 4; i++){
                int nrow = newRow + delRow[i];
                int ncol = newCol + delCol[i];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && newDis + 1 < dist[nrow][ncol]){
                    dist[nrow][ncol] = newDis + 1;
                    if(nrow == destination.first && ncol == destination.second) return dist[nrow][ncol];
                    pq.push({newDis + 1,{nrow, ncol}});
                }
            }
            
        }
        return -1;
        
    }
};
