class Solution {
	public:
	string minWindow(string &s, string &p) {
		// code here
		int lens = s.size();
		int lenp = p.size();
		
		unordered_map<char, int> freq;
		for(int i = 0; i < lenp; i++){
		    freq[p[i]]++;
		}
		
		int minLen = INT_MAX;
		int sIndex = -1;
		int l = 0;
		int r = 0;
		int count = 0;
		
		while(r < lens){
		    //if pres-inserted
		    if(freq[s[r]] > 0){
		        count++;
		    }
		    freq[s[r]]--;
		    
		    while(count == lenp){
		        if(r - l + 1 < minLen){
		            minLen = r - l + 1;
		            sIndex = l;
		        }
		        
		        freq[s[l]]++;
		        if(freq[s[l]] > 0) count--;
		        l++;
		    }
		    r++;
		}
		
		return sIndex == -1 ? "" : s.substr(sIndex, minLen);
		
	}
};
