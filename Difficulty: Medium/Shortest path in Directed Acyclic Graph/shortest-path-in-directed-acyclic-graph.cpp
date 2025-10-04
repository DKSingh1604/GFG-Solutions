// User function Template for C++
class Solution {
  public:
    void topoSort(int node,vector<vector<pair<int, int>>> &adjList, vector<int> &vis, stack<int> &st){
        
        vis[node] = 1;
        for(auto it : adjList[node]){
            int to = it.first;
            if(!vis[to]){
                topoSort(to, adjList, vis, st);
            }
        }
        
        st.push(node);
        
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        // making adjacency list
        vector<vector<pair<int, int>>> adjList(V);
        for(auto edge : edges){
            int from = edge[0];
            int to = edge[1];
            int weight = edge[2];
            adjList[from].push_back({to, weight});
        }
        
        //do a topo sort for the graph
        stack<int> st;
        vector<int> vis(V, 0);
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                topoSort(i, adjList, vis, st);
            }
        }
        
        //so the dist measurement
        vector<int> dist(V);
        for(int i = 0; i < V; i++) dist[i] = INT_MAX;
        
        dist[0] = 0;
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            for(auto it : adjList[node]){
                int v = it.first;
                int wt = it.second;
                
                if(dist[node] != INT_MAX && dist[node] + wt < dist[v]){
                    dist[v] = dist[node] + wt;
                }
            }
        }
        
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) dist[i] = -1;
        }

        return dist;
    }
};
