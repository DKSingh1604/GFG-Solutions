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
    static int kruskalsMST(int V, vector<vector<int>>& edges) {
        init(V);

        vector<pair<int, pair<int, int>>> edgeList;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            edgeList.push_back({wt, {u, v}});
        }

        sort(edgeList.begin(), edgeList.end());

        int mstWeight = 0;
        for (auto& e : edgeList) {
            int wt = e.first;
            int u = e.second.first;
            int v = e.second.second;

            if (findPar(u) != findPar(v)) {
                mstWeight += wt;
                unionSet(u, v);
            }
        }
        return mstWeight;
    }
};
vector<int> Solution::par;
vector<int> Solution::rank;