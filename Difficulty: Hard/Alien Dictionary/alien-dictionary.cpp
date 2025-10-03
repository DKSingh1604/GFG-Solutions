class Solution {
  public:
    string findOrder(vector<string> &words) {
        unordered_map<char, vector<char>> adj;
        vector<int> indegree(26, 0);
        unordered_set<char> chars; // track characters that appear

        // Collect all chars
        for (auto &w : words) {
            for (char c : w) chars.insert(c);
        }

        // Build graph
        for (int i = 0; i < words.size() - 1; i++) {
            string &w1 = words[i];
            string &w2 = words[i + 1];

            // Invalid case: prefix issue
            if (w1.size() > w2.size() && w1.find(w2) == 0) {
                return "";
            }

            for (int j = 0; j < min(w1.size(), w2.size()); j++) {
                if (w1[j] != w2[j]) {
                    adj[w1[j]].push_back(w2[j]);
                    indegree[w2[j] - 'a']++;
                    break; // only first difference matters
                }
            }
        }

        // Kahn’s Algorithm (Topological Sort)
        queue<char> q;
        for (char c : chars) {
            if (indegree[c - 'a'] == 0) q.push(c);
        }

        string result;
        while (!q.empty()) {
            char c = q.front(); q.pop();
            result.push_back(c);

            for (char nei : adj[c]) {
                if (--indegree[nei - 'a'] == 0) {
                    q.push(nei);
                }
            }
        }

        // If result doesn't include all characters → cycle / invalid
        if (result.size() < chars.size()) return "";

        return result;
    }
};