class Solution {
  public:
    vector<int> findOrder(int V, vector<vector<int>> prerequisites) {
        // code here
        vector<vector<int>> adj(V);
        for(auto it : prerequisites){
            int u = it[0];
            int v = it[1];
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
            reverse(topo.begin(), topo.end());
            return topo;
        }
        return {};
        
    }
};