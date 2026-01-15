#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    
    static vector<int> par;
    static vector<int> rank;

    static void init(int V) {
        par.resize(V);
        rank.assign(V, 0);
        for (int i = 0; i < V; i++) {
            par[i] = i;
        }
    }
    static int GetNumSets(){
        int cnt = 0;
        for(int i = 0; i < par.size(); i++){
            if(i == par[i]){
                cnt++;
            }
        }
        return cnt;
    }

    static int findPar(int x) {
        if (x == par[x]) 
            return x;
        return par[x] = findPar(par[x]);
    }

    static void unionSet(int a, int b) {
        int parA = findPar(a);
        int parB = findPar(b);

        if (parA == parB) return;

        if (rank[parA] < rank[parB]) {
            par[parA] = parB;
        } else if (rank[parB] < rank[parA]) {
            par[parB] = parA;
        } else {
            par[parB] = parA;
            rank[parA]++;
        }
    }

public:
    static int minConnect(int V, vector<vector<int>>& edges) {
        init(V);
        int extra = 0;
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            
            int pu = findPar(u);
            int pv = findPar(v);
            
            if(pu == pv){
                extra++;
            }
            else{
                unionSet(u, v);
            }
        }
        
        int num_comp = GetNumSets();
        if(num_comp - 1 > extra) return -1;
        return num_comp-1;
        
    }
};
vector<int> Solution::par;
vector<int> Solution::rank;