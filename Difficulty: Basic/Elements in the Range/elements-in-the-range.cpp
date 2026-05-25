class Solution {
  public:
    bool checkElements(int start, int end, vector<int> &arr) {
        // code here
        vector<bool> present(100001, false);

        for (int num : arr) {
            present[num] = true;
        }

        for (int i = start; i <= end; ++i) {
            if (!present[i]) {
               
                return false;
            }
        }

        
        return true;
    }
};
