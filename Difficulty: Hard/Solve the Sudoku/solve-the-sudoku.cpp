class Solution {
  public:
    
    void solveSudoku(vector<vector<int>> &mat) {
        // code here
        solve(mat);
    }
    
    bool solve(vector<vector<int>> &mat){
        
        int n = mat.size();
        //find the first empty cell;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    for(int digit = 1; digit <= 9; digit++){
                        if(isValid(mat, i, j, digit)){
                            mat[i][j] = digit;
                            
                            if(solve(mat) == true) {
                                return true;
                            }
                            else{
                                mat[i][j] = 0;
                            }
                        }
                        
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValid(vector<vector<int>> &mat, int row, int col, int digit){
        
        for(int i = 0; i < 9; i++){
            //check for row
            if(mat[row][i] == digit){
                return false;
            }
            
            //check for the col
            if(mat[i][col] == digit) return false;
            
            //check for that subsudoku
            if(mat[3 * (row/3) + i/3][3 * (col/3) + i%3] == digit){
                return false;
            }
        }
        return true;
    }
};