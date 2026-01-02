class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int, int>>> adj(V);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        //min heap
        priority_queue<
        pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;
        //(weight, node)
        pq.push({0, 0});
        
        vector<int> vis(V, 0);
        int sum = 0;
        
        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if(!vis[node]){
                vis[node] = 1;
                sum += wt;
                
                for(auto it : adj[node]){
                    if(!vis[it.first]){
                        pq.push({it.second, it.first});
                    }
                }
            }
        }
        return sum;
    }
};