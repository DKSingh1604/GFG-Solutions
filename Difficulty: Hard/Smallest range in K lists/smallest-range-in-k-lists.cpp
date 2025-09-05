class Solution {
  public:
    vector<int> findSmallestRange(vector<vector<int>>& arr) {
        vector<int> ans;
        
        vector<pair<int,int>> vec;
        
        int idx = 1;
        for(auto v : arr) {
            for(auto ele : v) {
                vec.push_back({ele, idx});
            }
            idx++;
        }
        
        sort(vec.begin(),vec.end());
        
        unordered_map<int,int> mp;
        
        int i=0,j=0;
        
        while(j < vec.size()) {
            auto ele = vec[j];
            
            mp[ele.second]++;
            
            if(mp.size() < arr.size()) {j++; continue;}
            
            while(i <= j and mp.size() == arr.size()) {
                if(ans.empty()) {
                    ans.push_back(vec[i].first);
                    ans.push_back(vec[j].first);
                } else {
                    int currDiff = vec[j].first - vec[i].first;
                    int oldDiff = ans.back() - ans.front();
                    
                    if(currDiff < oldDiff) {
                        ans[0] = vec[i].first;
                        ans[1] = vec[j].first;
                    }
                }
                
                if(!--mp[vec[i].second]) mp.erase(vec[i].second);
                
                i++;
            }
            
            j++;
        }
        
        return ans;
    }
};