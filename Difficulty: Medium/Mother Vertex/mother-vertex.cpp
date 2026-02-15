class Solution {
  public:
    // Function to find a Mother Vertex in the Graph.
    void dfs(vector<int> adj[], vector<int> &vis, int node, stack<int> &st){
        
        vis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]) dfs(adj, vis, it, st);
        }
        
        st.push(node);
    }
    int findMotherVertex(int V, vector<int> adj[]) {
        // Code here
        
        stack<int> st;
        vector<int> vis(V, 0);
        
        for(int i = 0; i < V; i++){
            if(!vis[i]) dfs(adj, vis, i, st);
        }
        
        for(int i = 0; i < V; i++){
            vis[i] = 0;
        }
        
        int candidate = st.top();
        
        dfs(adj, vis, candidate, st);
        
        for(int i = 0; i < V; i++){
            if(!vis[i]) return -1;
        }
        return candidate;
    }
};