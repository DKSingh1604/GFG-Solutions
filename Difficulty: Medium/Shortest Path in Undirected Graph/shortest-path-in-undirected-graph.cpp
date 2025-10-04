class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        
        //create adjacency list
        int n = adj.size();
        
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        queue<int> q;
        q.push(src);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it : adj[node]){
                
                if(dist[node] + 1 < dist[it]){
                    q.push(it);
                    dist[it] = dist[node] + 1;
                }
            }
        }
        
        for(auto &it : dist){
            if(it == INT_MAX){
                it = -1;
            }
        }
        return dist;
    }
};