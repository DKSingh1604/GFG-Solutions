class Solution {
  public:
    vector<int> topKFrequent(vector<int> &arr, int k) {
        // Your code here
        unordered_map<int, int> mp;
        
        for(int i = 0; i < arr.size(); i++){
            mp[arr[i]]++;
        }
        
        //max heap that takes pair from the map
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(pair<int, int> entry : mp){
            pq.push({entry.second, entry.first});
            if(pq.size() > k) pq.pop();
        }
        
        vector<int> res(k);
        
        for(int i = k-1; i >= 0; i--){
            res[i] = pq.top().second;
            pq.pop();
        }
        
        return res;
    }
};
