// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        for(int i = 0; i < V-1; i++){
            for(auto edge : edges){
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                
                if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                }
            }
        }
        //Nth interation to check if there is a negative cycle
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
                return {-1};
            }
        }
        
        for(int i = 0; i < V; i++){
            if(dist[i] == INT_MAX){
                dist[i] = 1e8;
            }
        }
        
        return dist;
    }
};
