class Solution {
	public:
	void findNextGen(vector<vector<int>> &mat) {
		
		// STEPS
		
		int n = mat.size();
		int m = mat[0].size();
		
		vector<vector<int>> res = mat;
		
		int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
		int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				// check if the cel is dead or alive
				if (mat[i][j]) {// alive
					int count = 0;
					for (int k = 0; k < 8; k++) {
						int ni = i + dx[k];
						int nj = j + dy[k];
						
						if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
							if (mat[ni][nj]) {
								count++;
							}
							
						}
						
					}
					if (count < 2 || count > 3) {
						res[i][j] = 0;
					}
					
				}
				else {// dead
					int count = 0;
					for (int k = 0; k < 8; k++) {
						int ni = i + dx[k];
						int nj = j + dy[k];
						
						if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
							if (mat[ni][nj]) {
								count++;
							}
							
						}
					}
					
					if (count == 3) {
						res[i][j] = 1;
					}
					
				}
			}
		}
		
		mat = res;
		
	}
};
