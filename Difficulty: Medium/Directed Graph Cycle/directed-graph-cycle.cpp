class Solution {
  public:
  //--------------Using DFs --------------------------------------------------
    // bool dfsCheck(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis){
        
    //     vis[node] = 1;
    //     pathVis[node] = 1;
        
    //     for(auto it : adj[node]){
    //         //if node not visited
    //         if(!vis[it]){
    //             if(dfsCheck(it, adj, vis, pathVis)) return true;
    //         }
            
    //         //if node is visited
    //         else if(pathVis[it]){
    //             return true;
    //         }
    //     }
        
    //     pathVis[node] = 0;
    //     return false;
               
    // }
    // bool isCyclic(int V, vector<vector<int>> &edges) {
    //     // code here
        
    //     vector<vector<int>> adj(V);
    //     for(auto edge : edges){
    //         int u = edge[0];
    //         int v = edge[1];
    //         adj[u].push_back(v);
    //     }
        
    //     vector<int> vis(V, 0);
    //     vector<int> pathVis(V, 0);
        
        
    //     for(int i = 0; i < V; i++){
    //         if(!vis[i]){
    //             if(dfsCheck(i, adj, vis, pathVis)) return true;
    //         }
    //     }
        
    //     return false;
    // }
    
    //-------------------------Using BFS---------------------------------------
    bool isCyclic(int V, vector<vector<int>> &edges) {
    
        vector<vector<int>> adj(V);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        
        int inDegree[V] = {0};
        
        //made the inDegree array
        for(int i = 0; i < V; i++){
            for(auto it : adj[i]){
                inDegree[it]++;
            }
        }
        
        //push the elements with 0 in degree into the queue
        queue<int> q;
        for(int i = 0; i < V; i++){
            if(inDegree[i] == 0){
               q.push(i); 
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto it : adj[node]){
                inDegree[it]--;
                if(inDegree[it] == 0){
                    q.push(it);
                }
            }
        }
        
        if(topo.size() == V){
            return false;
        }
        return true;
        
    }
};