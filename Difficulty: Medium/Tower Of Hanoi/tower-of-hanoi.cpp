class Solution {
  public:
    int towerOfHanoi(int n, int from, int to, int aux) {
        // code here
        int ans = 2;
        for(int i = 1; i < n; i++){
            ans = ans * 2;
        }
        return ans-1;
    }
};