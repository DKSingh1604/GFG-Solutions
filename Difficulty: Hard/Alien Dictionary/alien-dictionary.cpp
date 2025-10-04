class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        unordered_map<char, vector<char>> adj;
        vector<int> indegree(26, 0);
        unordered_set<char> chars;
        
        //step1 - collect all unique characters
        for(auto &w : words){
            for(auto c : w){
                chars.insert(c);
            }
        }
        
        //step2 - build a graph from the adjacent word pairs
        for(int i = 0; i < words.size()-1; i++){
            string &w1 = words[i];
            string &w2 = words[i+1];
            
            
            //prefix case handled
            if(w1.size() > w2.size() && w1.find(w2) == 0){
                return "";
            }
            
            for(int j = 0; j < min(w1.size(), w2.size()); j++){
                if(w1[j] != w2[j]){
                    adj[w1[j]].push_back(w2[j]);
                    indegree[w2[j] - 'a']++;
                    break;
                }
            }
            
        }
        
        //applying Kahn's algorithm
        queue<int> q;
        for(char c : chars){
            if(indegree[c -'a'] == 0){
                q.push(c);
            }
        }
        
        string ans = "";
        while(!q.empty()){
            char node = q.front();
            q.pop();
            ans += node;
            
            for(char nei : adj[node]){
                indegree[nei - 'a']--;
                if(indegree[nei - 'a'] == 0){
                    q.push(nei);
                }
            }
        }
        
        // check if valid ordering
        if(ans.size() < chars.size()){
            return "";
        }
        return ans;
        
        
    }
};