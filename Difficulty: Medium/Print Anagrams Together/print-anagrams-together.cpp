// User function Template for C++

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
        
        unordered_map<string, vector<string>> anagramMap;
        vector<string> keysOrder;
        vector<vector<string>> ans;
        
        for(int i = 0; i < arr.size(); i++){
            
            string originalElement = arr[i];
            
            sort(arr[i].begin(), arr[i].end());
            string sortedKeyOrder = arr[i];
            auto it = find(keysOrder.begin(), keysOrder.end(), sortedKeyOrder);
            // Check if element is preset
          	if (it != arr.end()){
                anagramMap[sortedKeyOrder].push_back(originalElement);
            }	
            else{
                keysOrder.push_back(sortedKeyOrder);
                
                anagramMap[sortedKeyOrder].push_back(originalElement);
            }
        }
        
        for (const auto& pair : anagramMap) {
            ans.push_back(pair.second);
        }
        return ans;
    }
};