class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int, int>>> adjList(V);
        for(auto edge : edges){
            int from = edge[0];
            int to = edge[1];
            int wt = edge[2];
            adjList[from].push_back({to, wt});
            adjList[to].push_back({from, wt});
        }
        
        priority_queue<pair<int, int>, 
        vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int vis[V] = {0};
        pq.push({0, 0});//{wt, node}
        int sum = 0;
        while(!pq.empty()){
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            
            if(vis[node] == 1) continue;
            
            vis[node] = 1;
            sum += wt;
            for(auto it : adjList[node]){
                if(!vis[it.first]){
                    pq.push({it.second, it.first});
                }
            }
        }
        return sum;
    }
};