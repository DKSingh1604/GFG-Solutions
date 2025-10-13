class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // Code here
        vector<vector<pair<int, int>>> adjList(n);
        for(auto it : flights){
            adjList[it[0]].push_back({it[1], it[2]}); //from : to, cost
        }
        
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        //stops, node, cost
        
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        
        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();
            
            if(stops > K) continue;
            for(auto it : adjList[node]){
                int adjNode = it.first;
                int edW = it.second;
                
                if(cost + edW < dist[adjNode] && stops <= K){
                    dist[adjNode] = cost + edW;
                    q.push({stops + 1, {adjNode, cost + edW}});
                }
            }
        }
        
        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};