class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
        // code here
        int m = mat.size();
        int n = mat[0].size();
        
        vector<int> ans;
        
        int top = 0;
        int bottom = m-1;
        int left = 0;
        int right = n-1;
        
        while(top <= bottom && left <= right){
            
            //going top left to top right
            for(int i = left; i <= right; i++){
                ans.push_back(mat[top][i]);
            }
            top++;
            
            //going top right to bottom right
            for(int i = top; i <= bottom; i++){
                ans.push_back(mat[i][right]);
            }
            right--;
            
            if(top <= bottom){
                //going bottom right to bottom left
                for(int i = right; i >= left; i--){
                    ans.push_back(mat[bottom][i]);
                }
                bottom--;
            }
            
            if(left <= right){
                //going from bottom left to top left
                for(int i = bottom; i >= top; i--){
                    ans.push_back(mat[i][left]);
                }
                left++;
            }
            
        }
        return ans;
     
    }
};