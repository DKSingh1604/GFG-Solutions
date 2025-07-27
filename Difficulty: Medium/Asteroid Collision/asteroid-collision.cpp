class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        stack<int> st;

        for (int i = 0; i < N; i++) {
            int curr = asteroids[i];
            bool destroyed = false;

            // Check for collision only if curr is moving left and top of stack is moving right
            while (!st.empty() && curr < 0 && st.top() > 0) {
                if (st.top() < -curr) {
                    st.pop(); // Current asteroid survives, keep checking
                } else if (st.top() == -curr) {
                    st.pop(); // Both destroy each other
                    destroyed = true;
                    break;
                } else {
                    destroyed = true; // Current asteroid destroyed
                    break;
                }
            }

            if (!destroyed) {
                st.push(curr);
            }
        }

        // Transfer stack to result vector
        vector<int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};
