class Solution {
  public:
    // void dfs(int node, vector<int> &vis, stack<int> &st, vector<vector<int>> &adj){
        
    //     vis[node] = 1;
    //     for(auto it: adj[node]){
    //         if(!vis[it]){
    //             dfs(it, vis, st, adj);
    //         }
    //     }
        
    //     st.push(node);
    // }
    
    
    // vector<int> topoSort(int V, vector<vector<int>>& edges) {
    //     // code here
    //     vector<vector<int>> adj(V);
    //     vector<int> vis(V, 0);
    //     stack<int> st;
    //     vector<int> ans;
    //     for(auto edge : edges){
    //         int u = edge[0];
    //         int v = edge[1];
    //         adj[u].push_back(v);
    //     }
        
    //     for(int i = 0; i < V; i++){
    //         if(!vis[i]){
    //             dfs(i, vis, st, adj);
    //         }
    //     }
    //     while(!st.empty()){
    //         ans.push_back(st.top());
    //         st.pop();
    //     }
        
    //     return ans;
    // }
    
    // -------------------Kahn's Algo - custom BFS-------------------------
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
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
        
        return topo;
    }
};