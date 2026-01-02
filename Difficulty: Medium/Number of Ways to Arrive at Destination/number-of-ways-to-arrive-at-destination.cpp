class Solution {
  public:
    int countPaths(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int, int>>> adj(V);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int t = edge[2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }
        
        priority_queue<
        pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;
        //(distance, node)
        pq.push({0, 0});
        
        vector<int> distance(V, INT_MAX);
        distance[0] = 0;
        
        vector<int> ways(V, 0);
        ways[0] = 1;
        
        int mod = (int)(1e9 + 7);
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                int newDist = it.second;
                
                if(newDist + dis < distance[adjNode]){
                    distance[adjNode] = newDist + dis;
                    pq.push({newDist + dis, adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(newDist + dis == distance[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[V-1] % mod;
        
    }
};