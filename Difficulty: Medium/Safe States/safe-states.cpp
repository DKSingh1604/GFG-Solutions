class Solution {
  public:
    bool dfsCheck(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis, vector<int> &check){
        
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfsCheck(it, adj, vis, pathVis, check)) return true;
            }
            else if(pathVis[it]) return true;
        }
        
        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }
    
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        vector<int> check(V, 0);
        vector<int> safeNodes;
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfsCheck(i, adj, vis, pathVis, check);
            }
        }
        
        for(int i = 0; i < V; i++){
            if(check[i] == 1){
                safeNodes.push_back(i);
            }
        }
        
        return safeNodes;
    }
};