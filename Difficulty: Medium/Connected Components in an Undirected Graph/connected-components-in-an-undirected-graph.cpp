
class Solution {
  public:
    void dfs(int node, int count, vector<vector<int>> &ans,  vector<int> &vis,  vector<vector<int>> &adjList){
        
        vis[node] = 1;
        ans[count].push_back(node);
        for(auto it : adjList[node]){
            if(!vis[it]){
                dfs(it, count, ans, vis, adjList);
            }
        }
        
        
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adjList(V);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        vector<vector<int>> ans;
        vector<int> vis(V, 0);
        int count = 0;
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                ans.push_back({});
                dfs(i, count, ans, vis, adjList);
                count++;
            }
        }
        return ans;
    }
};
