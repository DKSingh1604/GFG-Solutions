class Solution {
  public:
    void dfs(int node, vector<int> &vis, stack<int> &st, vector<vector<int>> &adj){
        
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, vis, st, adj);
            }
        }
        
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        
        vector<int> vis(V, 0);
        stack<int> st;
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i, vis, st, adj);
            }
        }
        
        vector<int> ans;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            ans.push_back(node);
        }
        
        return ans;
    }
};