class Solution {
  public:
    string FirstNonRepeating(string &s) {
        // Code here
        vector<int> freq(26, 0);  // frequency of each character
        queue<char> q;
        string ans = "";
    
        for (char ch : s) {
            freq[ch - 'a']++;    // step 1: update frequency
            q.push(ch);          // step 2: add to queue
    
            // step 3: remove from queue all repeating chars
            while (!q.empty() && freq[q.front() - 'a'] > 1) {
                q.pop();
            }
    
            // step 4: add to answer
            if (q.empty())
                ans += '#';
            else
                ans += q.front();
        }
    
        return ans;
    }
};