class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Your code here
        
        int n = points.size();
        int distance = 0;
        vector<pair<int,int>> distances;
        for(int i = 0; i < n; i ++){
            distance = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
            distances.push_back({distance, i});
            
        }
        
        priority_queue<pair<int,int>> maxi;
        
        for(int i = 0; i < k; i++){
            maxi.push(distances[i]);
        }
            
        
        //pop the maxi.top() if 
        for(int i = k; i < n; i++){
            if(distances[i].first < maxi.top().first){
                maxi.pop();
                maxi.push(distances[i]);
            }
        }
        vector<vector<int>> ans;
        while(!maxi.empty()){
            int idx = maxi.top().second;
            ans.push_back(points[idx]);
            maxi.pop();
        }
        
        return ans;
        
    }
};