class Solution {
  public:
    bool dfs(vector<vector<char>> &mat, string &word, int i, int j, int index, int n, int m){
        
        if(i < 0 || i >= n || j < 0 || j >= m){
            return false;
        }
        
        if(mat[i][j] != word[index]){
            return false;
        }
        
        if(index == word.size()-1){
            return true;
        }
        
        //mark as visited(#)
        char temp = mat[i][j];
        mat[i][j] = '#';
        
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        
        for(int d = 0; d < 4; d++){
            int ni = i + dx[d];
            int nj = j + dy[d];
            
            if(dfs(mat, word, ni, nj, index+1, n, m)) return true;
        }
        mat[i][j] = temp;
        return false;
        
    }
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        // Code here
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == word[0]){
                    if(dfs(mat, word, i, j, 0, n, m)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};