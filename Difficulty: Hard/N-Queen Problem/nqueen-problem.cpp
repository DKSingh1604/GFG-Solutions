class Solution {
	public:
	bool isSafe(int row, int col, vector<string> board, int n) {
		
		int duprow = row;
		int dupcol = col;
		
		// checking North-West
		while (row >= 0 && col >= 0) {
			if (board[row][col] == 'Q') {
				return false;
			}
			row--;
			col--;
		}
		
		row = duprow;
		col = dupcol;
		
		// checking left
		while (col >= 0) {
			if (board[row][col] == 'Q')
				return false;
			col--;
		}
		
		row = duprow;
		col = dupcol;
		
		// checking South West
		while (row < n && col >= 0) {
			if (board[row][col] == 'Q')
				return false;
			col--;
			row++;
		}
		return true;
		
	}
	void solve(int col, vector<string> &board, vector<vector<int>> &ans, int n) {
		
		// base case
		if (col == n) {
			vector<int> temp;
			for (int row = 0; row < n; row++) {
				for (int c = 0; c < n; c++) {
					if (board[row][c] == 'Q') {
						temp.push_back(c + 1); // GFG wants 1-based column
						break;
					}
				}
			}
			ans.push_back(temp);
			return;
		}
		
		for (int i = 0; i < n; i++) {
			if (isSafe(i, col, board, n)) {
				board[i][col] = 'Q';
				solve(col + 1, board, ans, n);
				board[i][col] = '.';
			}
		}
	}
	vector<vector<int>> nQueen(int n) {
		// code here
		vector<vector<int>> ans;
		vector<string> board(n);
		string s(n, '.');
		for (int i = 0; i < n; i++) {
			board[i] = s;
		}
		
		solve(0, board, ans, n);
		return ans;
	}
};
