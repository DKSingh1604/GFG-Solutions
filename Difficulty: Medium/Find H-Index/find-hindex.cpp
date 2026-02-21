class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        
        vector<int> freq(n + 1, 0);
        
        
        for(int c : citations){
            if(c >= n)
                freq[n]++;
            else
                freq[c]++;
        }
        
        int count = 0;
        
        
        for(int h = n; h >= 0; h--){
            count += freq[h];
            
            if(count >= h)
                return h;
        }
        
        return 0;
    }
};
