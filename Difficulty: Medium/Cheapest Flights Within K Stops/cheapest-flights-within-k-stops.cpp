class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // Code here
        vector<pair<int, int>> adj[n];
        for(auto flight : flights){
            adj[flight[0]].push_back({flight[1], flight[2]});// from: to, cost
            
        }
        
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}}); // stops, src, distance
        vector<int> distance(n, INT_MAX);
        distance[src] = 0;
        
        while(!q.empty()){
            
            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();
            
            if (stops > K) continue;
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                int edW = it.second;
                
                if(cost + edW < distance[adjNode] && stops <= K){
                    distance[adjNode] = cost + edW;
                    q.push({stops + 1, {adjNode, cost + edW}});
                }
            }
        }
        
        if(distance[dst] == INT_MAX) distance[dst] = -1;
        return distance[dst];
    }
};