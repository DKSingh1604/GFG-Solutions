class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int upu(int u){
        if (u==parent[u]) return u;
       return  parent[u]=upu(parent[u]);
       
    }
    void unibysize(int u,int v){
        if (upu(u)==upu(v)) return ;
        int up_u=upu(u);
        int up_v=upu(v);
        if (size[up_u]>size[up_v]){
            parent[up_v]=up_u;
            size[up_u]+=size[up_v];
        }
        else {
            parent[up_u]=up_v;
            size[up_v]+=size[up_u];
        }
    }
};

class Solution {
  public:
    vector<vector<string>> accMerge(vector<vector<string>>& arr) {
        
        
        int n = arr.size();
        unordered_map<string, int> mp;
        DisjointSet ds = DisjointSet(n);
        
        for(int i = 0; i < n; i++){
            int m = arr[i].size();
            for(int j = 1; j < m; j++){
                string mail = arr[i][j];
                
                if(mp.find(mail) == mp.end()){
                    mp[mail] = i;
                }
                else{
                    ds.unibysize(i, mp[mail]);
                }
            }
        }
        
        vector<vector<string>> mergeMail(n);
        for(auto it : mp){
            string mail = it.first;
            int node = ds.upu(it.second);//we have got out ultimate parent node
            mergeMail[node].push_back(mail);
        }
        
        vector<vector<string>> ans;
        for(int i = 0; i < n; i++){
            if(mergeMail[i].size() == 0){
                continue;
            }
            else{
                sort(mergeMail[i].begin(), mergeMail[i].end());
                vector<string> temp;
                temp.push_back(arr[i][0]); //name
                for(auto it : mergeMail[i]){
                    temp.push_back(it);
                }
                ans.push_back(temp);
            }
        }
        
        return ans;
    }
};
