class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, -1, 0, 1};
        
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[source.first][source.second] = 0;
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, 
                                                        greater <pair<int, pair<int, int>>>>pq;
        pq.push({0, {source.first, source.second}});
        
        while(!pq.empty()) {
            int distance = pq.top().first;
            int r = pq.top().second.first;
            int c= pq.top().second.second;
            pq.pop();
            
            if (r == destination.first && c == destination.second) {
                return distance;
            }
            
            for (int i = 0; i < 4; i++) {
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];
                
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 
                                            && distance + 1 < dist[nrow][ncol]) {
                    dist[nrow][ncol] = distance + 1;
                    pq.push({dist[nrow][ncol], {nrow, ncol}});
                }
            }
        }
        return -1;
        
    }
};