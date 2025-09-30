class Solution {
  public:
    bool dfsCheck(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis){
        
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto it : adj[node]){
            //if node not visited
            if(!vis[it]){
                if(dfsCheck(it, adj, vis, pathVis)) return true;
            }
            
            //if node is visited
            else if(pathVis[it]){
                return true;
            }
        }
        
        pathVis[node] = 0;
        return false;
               
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        
        vector<vector<int>> adj(V);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(dfsCheck(i, adj, vis, pathVis)) return true;
            }
        }
        
        return false;
    }
};