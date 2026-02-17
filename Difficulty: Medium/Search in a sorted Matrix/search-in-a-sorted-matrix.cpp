class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int start = 0;
        int end = mat[0].size() - 1;
        while(start < mat.size() && end >= 0){
            if(mat[start][end] == x) return true;
            else if(mat[start][end] < x) start++;
            else end--;
        }
        return false;
    }
};