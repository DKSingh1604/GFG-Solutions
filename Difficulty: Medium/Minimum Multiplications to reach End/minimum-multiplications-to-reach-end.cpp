// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        if(start == end) return 0;
        queue<pair<int, int>> q;
        q.push({0, start});
        
        vector<int> dist(100000, INT_MAX);
        dist[start] = 0;
        int mod = 100000;
        
        while(!q.empty()){
            int node = q.front().second;
            int operations = q.front().first;
            q.pop();
            
            for(auto it : arr){
                int num = (it * node) % mod;
                if(operations + 1 < dist[num]){
                    dist[num] = operations + 1;
                    if(num == end) return operations + 1;
                    q.push({operations + 1, num});
                }
            }
        }
        return -1;
    }
};
