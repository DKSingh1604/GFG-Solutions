// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int, int>>> adjList(V);
        for(auto edge : edges){
            int from = edge[0];
            int to = edge[1];
            int weight = edge[2];
            adjList[from].push_back({to, weight});
            adjList[to].push_back({from, weight});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V);
        for(int i = 0; i < V; i++) dist[i] = INT_MAX;
        
        dist[src] = 0;
        pq.push({0, src});
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adjList[node]){
                int adjNode = it.first;
                int edgeWeight = it.second;
                
                if(dis + edgeWeight < dist[adjNode]){
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
            
        }
        return dist;
    }
};