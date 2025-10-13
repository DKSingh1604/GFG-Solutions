class Solution {
  public:
    int findDelayTime(int V, vector<vector<int>> &edges, int src) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        for(auto &it : edges){
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dist(V, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[src] = 0;
        pq.push({0, src});
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto &it : adj[node]){
                int adjnode = it.first;
                int sigtime = it.second;
                
                if(dis + sigtime < dist[adjnode]){
                    dist[adjnode] = dis + sigtime;
                    pq.push({dist[adjnode], adjnode});
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < V; i++){
            if(dist[i] == INT_MAX) return -1; 
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};